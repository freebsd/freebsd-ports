http://github.com/pfenwick/finance-quote/commit/b897e9e2a328396480a7ef21fad2c94f8357baa6

--- lib/Finance/Quote/Tiaacref.pm.orig	2009-10-06 01:39:57.000000000 +0800
+++ lib/Finance/Quote/Tiaacref.pm	2010-11-05 19:34:30.000000000 +0800
@@ -44,7 +44,8 @@
 
 # URLs of where to obtain information.
 # This used to be different for the CREF and TIAA annuities, but this changed.
-$CREF_URL = ("https://www3.tiaa-cref.org/ddata/DownloadData?");
+$CREF_URL = ("http://www.tiaa-cref.org/public/performance/retirement/data/results?");
+#https://www3.tiaa-cref.org/ddata/DownloadData?");
 
 sub methods { return (tiaacref=>\&tiaacref); }
 
@@ -256,9 +257,21 @@
     my($ua,$urlc,$urlt);   #useragent and target urls
     my($cntc,$cntt); #counters for each of the two url containers
     my($reply,$qdata);		#the reply from TIAA-CREF's cgi and a buffer for the data
+    my $cbResult = 'cbResults=';
+
+    my ($Fsec,$Fmin,$Fhour,$Fmday,$Fmon,$Fyear,$Fwday,$Fyday,$Fisdst) = localtime(time() - 24 * 60 * 60);
+    my ($Tsec,$Tmin,$Thour,$Tmday,$Tmon,$Tyear,$Twday,$Tyday,$Tisdst) = localtime(time());
+
+    $urlc  = $CREF_URL;
+    $urlc .= "page=input";
+    $urlc .= "&frommonth=" . ($Fmon + 1);
+    $urlc .= "&fromday=" . ($Fmday);
+    $urlc .= "&fromyear=" . ($Fyear + 1900);
+    $urlc .= "&tomonth=" . ($Tmon + 1);
+    $urlc .= "&today=" . ($Tmday);
+    $urlc .= "&toyear=" . ($Tyear + 1900);
+    $urlc .= "&sqlorder=desc&dldformat=1&submit.x=29&submit.y=7";
 
-#    $url = $TIAACREF_URL;
-    $urlc = $CREF_URL;
     $urlt = $TIAA_URL;
 #Initialize counters for the two types of URL. If either counter is zero, then
 # that URL will not be retrieved. This is less technically clever than testing
@@ -269,7 +282,8 @@
 	if ($tiaacref_ids{$fund}) {
         	if ($tiaacref_locs{$fund} == 1) {
 			$cntc++;
-			$urlc .=  "f" . $cntc . "=" . $tiaacref_vals{$fund} . "&";
+			$urlc .= "&fundid" . $tiaacref_vals{$fund} . "=" . $tiaacref_vals{$fund};
+			$cbResult .= ($cntc > 1) ? ( "%2C" . $tiaacref_vals{$fund}) : ($tiaacref_vals{$fund})
 		} else {
  			$urlt .= $fund . "=yes&";
 			$cntt++;
@@ -280,8 +294,7 @@
 		$info{$fund,"errormsg"} = "Bad symbol";
 	}
     }
-    $urlc .=  "days=1";
-    $urlc .=  "&dldformat=1";
+    $urlc .=  "&$cbResult";
     $urlt .=  "selected=1";
     $qdata ="";
 
@@ -298,9 +311,14 @@
             $qdata .= $reply->content;
 	}
     }
+
     if (length($qdata)) {
-       foreach (split('\012',$qdata) ){
+       foreach (split(/<br .>/,$qdata) ){
+	   next unless m/.+,.+/;
+	   s/^ +//g;
+	   s/ +$//g;
            @line = $quoter->parse_csv($_);
+
            if (exists $check{$line[0]}) {   #did we ask for this data?
 		  $info{$line[0],"symbol"} = $line[0]; #in case the caller needs this in the hash
          	  $info{$line[0],"exchange"} = "TIAA-CREF";
