--- lib/Finance/Quote.pm.orig	2012-08-31 15:38:42.023832749 +0200
+++ lib/Finance/Quote.pm	2012-08-31 15:42:45.299834285 +0200
@@ -35,7 +35,6 @@
 use Carp;
 use Finance::Quote::UserAgent;
 use HTTP::Request::Common;
-use HTML::TreeBuilder;
 use Encode;
 use Data::Dumper;
 
@@ -43,7 +42,14 @@
             $VERSION $TIMEOUT %MODULES %METHODS $AUTOLOAD
             $YAHOO_CURRENCY_URL $USE_EXPERIMENTAL_UA/;
 
-$YAHOO_CURRENCY_URL = "http://uk.finance.yahoo.com/q?s=";
+# Call on the Yahoo API:
+#  - "f=l1" should return a single value - the "Last Trade (Price Only)"
+#  - "s=" the value of s should be "<FROM><TO>=X"
+#         where <FROM> and <TO> are currencies
+# Excample: http://finance.yahoo.com/d/quotes.csv?f=l1&s=AUDGBP=X
+# Documentation can be found here:
+#     http://code.google.com/p/yahoo-finance-managed/wiki/csvQuotesDownload
+$YAHOO_CURRENCY_URL = "http://finance.yahoo.com/d/quotes.csv?e=.csv&f=l1&s=";
 
 @ISA    = qw/Exporter/;
 @EXPORT = ();
@@ -240,26 +246,13 @@
 
   my $ua = $this->user_agent;
 
-  my $data = $ua->request(GET "${YAHOO_CURRENCY_URL}$from$to%3DX")->content;
-  # The web page returns utf8 content which gives a warning when parsing $data
-  # in HTML::Parser
-  my $tb = HTML::TreeBuilder->new_from_content(decode_utf8($data));
-
-  # Find the <div> with the data
-  my $div = $tb->look_down('id','yfi_quote_summary_data');
-  # Make sure there's a <div> to parse.
-  return undef unless $div;
-
-  # The first <b> should contain the quote
-  my $rate_element=$div->look_down('_tag','b');
-  # Make sure there's a <b> to parse.
-  return undef unless $rate_element;
-
-  my $exchange_rate=$rate_element->as_text;
-
-        $exchange_rate =~ s/,// ; # solve a bug when conversion rate
-                                  # involves thousands. yahoo inserts
-                                  # a comma when thousands occur
+  # The response should be a single value (the exchange rate)
+  my $data = $ua->request(GET "${YAHOO_CURRENCY_URL}${from}${to}=X")->content;
+  my $exchange_rate = $data;
+
+  $exchange_rate =~ s/,// ; # solve a bug when conversion rate
+                            # involves thousands. yahoo inserts
+                            # a comma when thousands occur
 
   {
     local $^W = 0;  # Avoid undef warnings.
@@ -268,6 +261,18 @@
     # we may have extra cruft, or no amount.
     return undef unless ($exchange_rate+0);
   }
+
+if ( $exchange_rate < 0.001 ) {
+    # exchange_rate is too little. we'll get more accuracy by using
+    # the inverse rate and inverse it
+    my $inverse_rate = $this->currency( $to, $from );
+    {
+        local $^W = 0;
+        return undef unless ( $exchange_rate + 0 );
+    }
+    $exchange_rate = int( 100000000 / $inverse_rate + .5 ) / 100000000;
+}
+
   return ($exchange_rate * $amount);
 }
 
@@ -770,6 +775,60 @@
   return $retTime;
 }
 
+
+# If $str ends with a B like "20B" or "1.6B" then expand it as billions like
+# "20000000000" or "1600000000".
+#
+# This is done with string manipulations so floating-point rounding doesn't
+# produce spurious digits for values like "1.6" which aren't exactly
+# representable in binary.
+#
+# Is "B" for billions the only abbreviation from Yahoo?
+# Could extend and rename this if there's also millions or thousands.
+#
+# For reference, if the value was just for use within perl then simply
+# substituting to exponential "1.5e9" might work.  But expanding to full
+# digits seems a better idea as the value is likely to be printed directly
+# as a string.
+sub B_to_billions {
+
+  my ($self,$str) = @_;
+  ### B_to_billions(): $str
+  if ($str =~ s/B$//i) {
+    $str = $self->decimal_shiftup ($str, 9);
+  }
+  return $str;
+}
+
+# $str is a number like "123" or "123.45"
+# return it with the decimal point moved $shift places to the right
+# must have $shift>=1
+# eg. decimal_shiftup("123",3)    -> "123000"
+#     decimal_shiftup("123.45",1) -> "1234.5"
+#     decimal_shiftup("0.25",1)   -> "2.5"
+#
+sub decimal_shiftup {
+  my ($self, $str, $shift) = @_;
+
+  # delete decimal point and set $after to count of chars after decimal.
+  # Leading "0" as in "0.25" is deleted too giving "25" so as not to end up
+  # with something that might look like leading 0 for octal.
+  my $after = ($str =~ s/(?:^0)?\.(.*)/$1/ ? length($1) : 0);
+
+  $shift -= $after;
+  # now $str is an integer and $shift is relative to the end of $str
+
+  if ($shift >= 0) {
+    # moving right, eg. "1234" becomes "12334000"
+    return $str . ('0' x $shift);  # extra zeros appended
+  } else {
+    # negative means left, eg. "12345" becomes "12.345"
+    # no need to prepend zeros since demanding initial $shift>=1
+    substr ($str, $shift,0, '.');  # new '.' at shifted spot from end
+    return $str;
+  }
+}
+
 # Dummy destroy function to avoid AUTOLOAD catching it.
 sub DESTROY { return; }
 
@@ -803,7 +862,7 @@
 This module gets stock quotes from various internet sources, including
 Yahoo! Finance, Fidelity Investments, and the Australian Stock Exchange.
 There are two methods of using this module -- a functional interface
-that is depreciated, and an object-orientated method that provides
+that is deprecated, and an object-orientated method that provides
 greater flexibility and stability.
 
 With the exception of straight currency exchange rates, all information
