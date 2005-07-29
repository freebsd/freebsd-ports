--- tools/source/rc/resmgr.cxx.orig	Mon Feb 24 17:46:55 2003
+++ tools/source/rc/resmgr.cxx	Tue Feb 25 17:09:39 2003
@@ -1189,6 +1189,8 @@
                 return "36";
             case LANGUAGE_RUSSIAN:
                 return "07";
+            case LANGUAGE_UKRAINIAN:
+                return "38";
             case LANGUAGE_SLOVAK:
                 return "04";
             case LANGUAGE_GREEK:
@@ -1339,6 +1341,7 @@
         LANGUAGE_HUNGARIAN,
         LANGUAGE_CZECH,
         LANGUAGE_RUSSIAN,
+        LANGUAGE_UKRAINIAN,
         LANGUAGE_ARABIC,
         LANGUAGE_GREEK,
         LANGUAGE_KOREAN,
