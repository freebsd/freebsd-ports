http://github.com/pfenwick/finance-quote/commit/7de984bea80e9c5e00504ededba6897183bb8c45

--- lib/Finance/Quote/BSERO.pm.orig	1970-01-01 08:00:00.000000000 +0800
+++ lib/Finance/Quote/BSERO.pm	2010-02-13 18:25:22.000000000 +0800
@@ -0,0 +1,183 @@
+#!/usr/bin/perl -w
+#    This modules is based on the Finance::Quote::ASEGR module
+#
+#    The code has been modified by Andrei Cipu <strainu@strainu.ro> to be able to
+#    retrieve stock information from the Bucharest Exchange in Romania.
+#
+#    This program is free software; you can redistribute it and/or modify
+#    it under the terms of the GNU General Public License as published by
+#    the Free Software Foundation; either version 2 of the License, or
+#    (at your option) any later version.
+#
+#    This program is distributed in the hope that it will be useful,
+#    but WITHOUT ANY WARRANTY; without even the implied warranty of
+#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+#    GNU General Public License for more details.
+#
+#    You should have received a copy of the GNU General Public License
+#    along with this program; if not, write to the Free Software
+#    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
+#    02111-1307, USA
+require 5.005;
+
+use strict;
+
+package Finance::Quote::BSERO;
+
+use vars qw($VERSION $BSERO_URL);
+
+use LWP::UserAgent;
+use HTTP::Request::Common;
+use HTML::TableExtract;
+
+$VERSION='0.1';
+
+my $BSERO_URL = 'http://www.bvb.ro/mobile/m_SecurityDetails.aspx?';
+
+
+sub methods { return ( romania => \&bsero,
+                       bsero => \&bsero,
+                       europe => \&bsero); }
+{
+  my @labels = qw/name last date isodate p_change open high low close volume currency method exchange/;
+
+  sub labels { return (romania => \@labels,
+                       bsero => \@labels,
+                       europe => \@labels); }
+}
+
+sub bsero {
+
+  my $quoter = shift;
+  my @stocks = @_;
+  my (%info,$reply,$url,$te,$ts,$row,@cells, $ce);
+  my($my_date,$my_last,$my_p_change,$my_volume,$my_high,$my_low,$my_open);
+  my $ua = $quoter->user_agent();
+
+  $url = $BSERO_URL;
+
+  foreach my $stocks (@stocks)
+    {
+      $reply = $ua->request(GET $url.join('',"s=",$stocks));
+
+      if ($reply->is_success)
+        {
+			
+          $te = new HTML::TableExtract();
+
+          $te->parse($reply->content);
+
+          unless ( $te->tables)
+            {
+              $info {$stocks,"success"} = 0;
+              $info {$stocks,"errormsg"} = "Stock name $stocks not found";
+              next;
+            }
+
+          $ts = $te->first_table_found();
+
+          foreach $row ($ts->rows) {
+            @cells = @$row;
+
+            # The date is not a number, so we don't bother modifying it
+            if($cells[0] eq 'Data'){
+              $my_date = $cells[1];
+            }
+            #The rest of the data needs to be modified
+            else {
+              foreach $ce (@cells) {
+                next unless $ce;
+                $ce =~ s/\.//;    #remove thouthand separator
+                $ce =~ s/,/\./g; #replace european decimal separator with american ones
+              }
+
+              #go through each row and get the data
+              if($cells[0] eq 'Ultimul pret'){
+                $my_last = $cells[1];
+              }
+              if($cells[0] eq 'Var (%)'){
+                $my_p_change = $cells[1];
+              }
+              if($cells[0] eq 'Volum'){
+                $my_volume = $cells[1];
+              }
+              if($cells[0] eq 'Pret maxim'){
+                $my_high = $cells[1];
+              }
+              if($cells[0] eq 'Pret minim'){
+                $my_low = $cells[1];
+              }
+              if($cells[0] eq 'Pret deschidere'){
+                $my_open = $cells[1];
+              }
+            }
+          }
+
+          $info{$stocks, "success"}  =1;
+          $info{$stocks, "exchange"} ="Bucharest Stock Exchange";
+          $info{$stocks, "method"}   ="bsero";
+          $info{$stocks, "name"}     =$stocks;
+          $info{$stocks, "last"}     =$my_last;
+          $info{$stocks, "close"}    =$my_last;
+          $info{$stocks, "p_change"} =$my_p_change;
+          $info{$stocks, "volume"}   =$my_volume;
+          $info{$stocks, "high"}     =$my_high;
+          $info{$stocks, "low"}      =$my_low;
+          $info{$stocks, "open"}     =$my_open;
+
+          $quoter->store_date(\%info, $stocks, {eurodate => $my_date});
+
+          $info{$stocks,"currency"} = "RON";
+
+        } else {
+          $info{$stocks, "success"}=0;
+          $info{$stocks, "errormsg"}="Error retreiving $stocks ";
+        }
+    }
+  return wantarray() ? %info : \%info;
+  return \%info;
+}
+
+1;
+
+=head1 NAME
+
+Finance::Quote::BSERO Obtain quotes from Bucharest Stock Exchange.
+
+=head1 SYNOPSIS
+
+    use Finance::Quote;
+
+    $q = Finance::Quote->new;
+
+    %info = Finance::Quote->fetch("bsero","tlv");  # Only query BSERO
+    %info = Finance::Quote->fetch("romania","brd"); # Failover to other sources OK.
+
+=head1 DESCRIPTION
+
+This module fetches information from the "Bucharest Stock Exchange"
+(Bursa de Valori Bucuresti), http://www.bvb.ro. All stocks are available.
+
+This module is loaded by default on a Finance::Quote object. It's
+also possible to load it explicity by placing "BSERO" in the argument
+list to Finance::Quote->new().
+
+This module provides both the "bsero" and "romania" fetch methods.
+Please use the "romania" fetch method if you wish to have failover
+with future sources for Romanian stocks. Using the "bsero" method will
+guarantee that your information only comes from the Bucharest Stock Exchange.
+
+Information obtained by this module may be covered by www.bvb.go
+terms and conditions See http://www.bvb.ro/ for details.
+
+=head1 LABELS RETURNED
+
+The following labels may be returned by Finance::Quote::BSERO :
+name, last, date, p_change, open, high, low, close,
+volume, currency, method, exchange.
+
+=head1 SEE ALSO
+
+Bucharest Stock Exchange, http://www.bvb.ro
+
+=cut
