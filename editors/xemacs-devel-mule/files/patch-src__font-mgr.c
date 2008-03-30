Index: src/font-mgr.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/font-mgr.c,v
retrieving revision 1.7
retrieving revision 1.8
diff -u -r1.7 -r1.8
--- src/font-mgr.c	2007/05/01 14:22:38	1.7
+++ src/font-mgr.c	2007/12/21 00:05:49	1.8
@@ -898,10 +898,8 @@
 		intern ("fc-config-get-blanks"));
 }
 
-/* The misspelling in the fontconfig function name accurately corresponds to
-   the version of fontconfig.h I had on 2007-04-13. -- sjt */
 DEFUN("fc-config-get-rescan-interval", Ffc_config_get_rescan_interval, 1, 1, 0, /*
- -- Function: int FcConfigGetRescanInverval (FcConfig *config)
+ -- Function: int FcConfigGetRescanInterval (FcConfig *config)
      Returns the interval between automatic checks of the configuration
      (in seconds) specified in 'config'.  The configuration is checked
      during a call to FcFontList when this interval has passed since
@@ -909,13 +907,11 @@
       (config))
 {
   CHECK_FCCONFIG (config);
-  return make_int (FcConfigGetRescanInverval (XFCCONFIG_PTR (config)));
+  return make_int (FcConfigGetRescanInterval (XFCCONFIG_PTR (config)));
 }
 
-/* The misspelling in the fontconfig function name accurately corresponds to
-   the version of fontconfig.h I had on 2007-04-13. -- sjt */
 DEFUN("fc-config-set-rescan-interval", Ffc_config_set_rescan_interval, 2, 2, 0, /*
- -- Function: FcBool FcConfigSetRescanInverval (FcConfig *config, int
+ -- Function: FcBool FcConfigSetRescanInterval (FcConfig *config, int
           rescanInterval)
      Sets the rescan interval; returns FcFalse if an error occurred.
      XEmacs: signal such error, or return nil on success. */
@@ -923,7 +919,7 @@
 {
   CHECK_FCCONFIG (config);
   CHECK_INT (rescan_interval);
-  if (FcConfigSetRescanInverval (XFCCONFIG_PTR (config),
+  if (FcConfigSetRescanInterval (XFCCONFIG_PTR (config),
 				 XINT (rescan_interval)) == FcFalse)
     signal_error (Qio_error, "FcConfigSetRescanInverval barfed",
 		  intern ("fc-config-set-rescan-interval"));
