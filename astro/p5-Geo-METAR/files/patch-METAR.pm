--- METAR.pm.orig	Sat Nov 25 01:07:51 2000
+++ METAR.pm	Fri Sep  3 20:33:01 2004
@@ -95,9 +95,13 @@
 
 # PRESSURE
 #
+# USA and Canada:
 # The pressure, or altimeter setting, at the reporting site recorded in
 # inches of mercury (Hg) minus the decimal point. It should always look
 # like (A\d\d\d\d).
+# Rest of the World:
+# The pressure, or altimeter setting, at the reporting site recorded in
+# hectopascals(hPa). It should always look like (Q\d\d\d\d).
 
 # REMARKS
 #
@@ -164,6 +168,7 @@
 my %_sky_types = (
 	SKC => "Sky Clear",
 	CLR => "Sky Clear",
+	CAVOK => "Sky Clear",
 	SCT => "Scattered",
 	BKN => "Broken",
 	FEW => "Few",
@@ -366,52 +371,87 @@
     $self->{type} = "METAR";
     $self->{TYPE} = "Routine Weather Report";
 
-    while (defined($tok = shift(@toks))) ## as long as there are tokens
+    $tok = shift(@toks);
+    print "trying to match [$tok]\n" if $self->{debug};
+
+    ##
+    ## is it a report type?
+    ##
+
+    if (($tok =~ /METAR/i) or ($tok =~ /SPECI/i))
     {
+        $self->{type} = $tok;
+
+        if ($self->{type} eq "METAR")
+        {
+            $self->{TYPE} = "Routine Weather Report";
+        }
+        elsif ($self->{type} eq "SPECI")
+        {
+            $self->{TYPE} = "Special Weather Report";
+        }
+        print "[$tok] is a report type.\n" if $self->{debug};
+
+        $tok = shift(@toks);
         print "trying to match [$tok]\n" if $self->{debug};
 
         ##
-        ## is it a report type?
+        ## is it a site ID?
         ##
 
-        if (($tok =~ /METAR/i) or ($tok =~ /SPECI/i))
+        if ($tok =~ /[A-Z]{4,4}/)
         {
-            $self->{type} = $tok;
-
-            if ($self->{type} eq "METAR")
-            {
-                $self->{TYPE} = "Routine Weather Report";
-            }
-            elsif ($self->{type} eq "SPECI")
-            {
-                $self->{TYPE} = "Special Weather Report";
-            }
-            print "[$tok] is a report type.\n" if $self->{debug};
-            next;
+            $self->{site} = $tok;
+            print "[$tok] is a site ID.\n" if $self->{debug};
         }
 
         ##
-        ## is is a site ID?
+        ## Most likely something is wrong, but to be sure put the token back
+        ## on the stack
         ##
 
-        elsif ($tok =~ /K[A-Z]{3,3}/)
+        else
         {
-            $self->{site} = $tok;
-            print "[$tok] is a site ID.\n" if $self->{debug};
-            next;
+	    unshift(@toks,$tok);
         }
 
+    }
+
+    ##
+    ## is it a site ID?
+    ##
+
+    elsif ($tok =~ /[A-Z]{4,4}/)
+    {
+        $self->{site} = $tok;
+        print "[$tok] is a site ID.\n" if $self->{debug};
+    }
+
+    ##
+    ## Most likely something is wrong, but to be sure put the token back
+    ## on the stack
+    ##
+
+    else
+    {
+        unshift(@toks,$tok);
+    }
+
+    # The order of the remaining stack is not defined, so do a patternmatching loop
+
+    while (defined($tok = shift(@toks))) ## as long as there are tokens
+    {
+        print "trying to match [$tok]\n" if $self->{debug};
+
         ##
         ## is it a date/time?
         ##
 
-        elsif ($tok =~ /\d{6,6}Z/i)
+        if ($tok =~ /\d{6,6}Z/i)
         {
             $self->{date_time} = $tok;
             print "[$tok] is a date/time.\n" if $self->{debug};
             next;
-
-
         }
 
         ##
@@ -447,6 +487,14 @@
             next;
         }
 
+	## 9999 == visibility is better than 10 km
+	elsif ($tok eq "9999")
+	{
+            $self->{visibility} = $tok;
+            print "[$tok] is visibility information.\n" if $self->{debug};
+            next;
+        }
+
         ##
         ## is it visibility information with a leading digit?
         ##
@@ -526,7 +574,7 @@
         ## is it sky conditions (clear)?
         ##
 
-        elsif ( $tok eq "SKC" || $tok eq "CLR" )
+        elsif ( $tok eq "SKC" || $tok eq "CLR" || $tok eq "CAVOK")
         {
             push(@{$self->{sky}},$tok);
             push(@{$self->{SKY}}, "Sky Clear");
@@ -588,10 +636,20 @@
         ## is it an altimeter setting?
         ##
 
+	## Northamerican setting in inches
         elsif (!$in_remarks && $tok =~ /^A(\d\d)(\d\d)$/i)
         {
             $self->{alt} = $tok;
             $self->{ALT} = "$1.$2";
+            print "[$tok] is an altimeter setting.\n" if $self->{debug};
+            next;
+        }
+
+	## setting in hectopascals (hPa)
+	elsif (!$in_remarks && $tok =~ /^Q(\d\d)(\d\d)$/i)
+        {
+            $self->{alt} = $tok;
+            $self->{ALT} = "$1$2";
             print "[$tok] is an altimeter setting.\n" if $self->{debug};
             next;
         }
