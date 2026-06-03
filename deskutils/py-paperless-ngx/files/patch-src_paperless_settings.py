--- src/paperless/settings.py.orig	2025-08-17 20:46:35 UTC
+++ src/paperless/settings.py
@@ -25,7 +25,6 @@ logger = logging.getLogger("paperless.settings")
 for path in [
     os.getenv("PAPERLESS_CONFIGURATION_PATH"),
     "../paperless.conf",
-    "/etc/paperless.conf",
     "/usr/local/etc/paperless.conf",
 ]:
     if path and Path(path).exists():
@@ -273,7 +272,7 @@ THUMBNAIL_DIR = MEDIA_ROOT / "documents" / "thumbnails
 
 DATA_DIR = __get_path("PAPERLESS_DATA_DIR", BASE_DIR.parent / "data")
 
-NLTK_DIR = __get_path("PAPERLESS_NLTK_DIR", "/usr/share/nltk_data")
+NLTK_DIR = __get_path("PAPERLESS_NLTK_DIR", "/usr/local/share/nltk_data")
 
 # Check deprecated setting first
 EMPTY_TRASH_DIR = (
@@ -1279,7 +1278,7 @@ FILENAME_FORMAT_REMOVE_NONE = __get_boolean(
 
 THUMBNAIL_FONT_NAME = os.getenv(
     "PAPERLESS_THUMBNAIL_FONT_NAME",
-    "/usr/share/fonts/liberation/LiberationSerif-Regular.ttf",
+    "/usr/local/share/fonts/Liberation/LiberationSerif-Regular.ttf",
 )
 
 # Tika settings
