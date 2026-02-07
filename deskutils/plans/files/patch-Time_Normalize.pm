--- Time/Normalize.pm.orig	2015-02-06 12:35:41 UTC
+++ Time/Normalize.pm
@@ -126,7 +126,7 @@ sub _setup_locale
     eval
     {
         require I18N::Langinfo;
-        I18N::Langinfo->import qw(langinfo);
+        I18N::Langinfo->import (qw(langinfo));
         @Mon_Name  = map langinfo($_), (
                                         I18N::Langinfo::MON_1(),
                                         I18N::Langinfo::MON_2(),
