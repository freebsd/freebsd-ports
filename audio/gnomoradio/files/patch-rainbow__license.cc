--- rainbow/license.cc.orig	Wed Dec 22 11:05:36 2004
+++ rainbow/license.cc	Wed Dec 22 11:06:49 2004
@@ -54,7 +54,7 @@
 	}
 	
 	if (done) {
-		signal<void,ref_ptr<License> > sig;
+		sigc::signal<void,ref_ptr<License> > sig;
 		sig.connect(slot);
 		sig(license);
 	} else {
