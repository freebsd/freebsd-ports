--- src/Configuration.hh.orig	Mon Apr 25 13:12:16 2005
+++ src/Configuration.hh	Mon Apr 25 13:12:40 2005
@@ -145,7 +145,7 @@
      verbose(),
      // had been "_glade"
      template_postfix("_new"),
-     source_suffix(".cc"), header_suffix(".hh"),  gettext_source(),
+     source_suffix(".cc"), header_suffix(".hh"),  gettext_source(GT_NONE),
      custom_signal_args("")
    {  if (gnome2) select_Gnome2();
       else select_Gnome1();
