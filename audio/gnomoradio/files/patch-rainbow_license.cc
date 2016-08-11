--- rainbow/license.cc.orig	2004-10-17 04:03:47 UTC
+++ rainbow/license.cc
@@ -54,7 +54,7 @@ void Rainbow::License::get_and_do (const
 	}
 	
 	if (done) {
-		signal<void,ref_ptr<License> > sig;
+		sigc::signal<void,ref_ptr<License> > sig;
 		sig.connect(slot);
 		sig(license);
 	} else {
