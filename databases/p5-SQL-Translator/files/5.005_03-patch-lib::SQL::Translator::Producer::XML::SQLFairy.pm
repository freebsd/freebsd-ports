--- lib/SQL/Translator/Producer/XML/SQLFairy.pm.orig	Sun May  9 15:11:42 2004
+++ lib/SQL/Translator/Producer/XML/SQLFairy.pm	Sun May  9 15:13:45 2004
@@ -224,9 +224,9 @@
         # Use array to ensure consistant (ie not hash) ordering of attribs
         # The order comes from the meths list passes in.
         my @attr = map {
-            my $val = $obj->$_;
+            my $val = $obj->$_();
             ($_ => ref($val) eq 'ARRAY' ? join(', ', @$val) : $val);
-        } grep { defined $obj->$_ } @meths;
+        } grep { defined $obj->$_() } @meths;
         $empty_tag ? $xml->emptyTag( [ $Namespace => $tag ], @attr )
                    : $xml->startTag( [ $Namespace => $tag ], @attr );
     }
@@ -247,7 +247,7 @@
     my $emit_empty            = $PArgs->{'emit_empty_tags'};
 
     for my $method ( @methods ) {
-        my $val = $obj->$method;
+        my $val = $obj->$method();
         debug "        ".ref($obj)."->$method=",
               (defined $val ? "'$val'" : "<UNDEF>");
         next unless $emit_empty || defined $val;
