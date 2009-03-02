--- include/rudiments/serialportprofile.h
+++ include/rudiments/serialportprofile.h
@@ -129,9 +129,15 @@
 
 		#ifdef TABDLY
 		enum	tabdelay_t {
+			#ifdef TAB0
 			td_none=TAB0,
+			#endif
+			#ifdef TAB1
 			td_depends=TAB1,
+			#endif
+			#ifdef TAB2
 			td_100=TAB2
+			#endif
 		};
 		#endif
 
