--- src/options.cpp.orig	2015-03-09 05:25:34 UTC
+++ src/options.cpp
@@ -513,8 +513,8 @@ void initOptions()
                                    false
                                   );
 
-    OPTIONS["AUTOSAFEMODETURNS"] = cOpt("general", _("Turns to reenable safemode"),
-                                        _("Number of turns after safemode is reenabled if no hostiles are in safemodeproximity distance."),
+    OPTIONS["AUTOSAFEMODETURNS"] = cOpt("general", _("Turns to re-enable safemode"),
+                                        _("Number of turns after safemode is re-enabled if no hostiles are in safemodeproximity distance."),
                                         1, 100, 50
                                        );
 
