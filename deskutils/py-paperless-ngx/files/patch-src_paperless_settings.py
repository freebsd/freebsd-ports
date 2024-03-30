--- src/paperless/settings.py.orig	2024-03-18 03:45:09 UTC
+++ src/paperless/settings.py
@@ -24,8 +24,6 @@ if configuration_path and os.path.exists(configuration
     load_dotenv(configuration_path)
 elif os.path.exists("../paperless.conf"):
     load_dotenv("../paperless.conf")
-elif os.path.exists("/etc/paperless.conf"):
-    load_dotenv("/etc/paperless.conf")
 elif os.path.exists("/usr/local/etc/paperless.conf"):
     load_dotenv("/usr/local/etc/paperless.conf")
 
@@ -254,7 +252,7 @@ THUMBNAIL_DIR = MEDIA_ROOT / "documents" / "thumbnails
 
 DATA_DIR = __get_path("PAPERLESS_DATA_DIR", BASE_DIR.parent / "data")
 
-NLTK_DIR = __get_path("PAPERLESS_NLTK_DIR", "/usr/share/nltk_data")
+NLTK_DIR = __get_path("PAPERLESS_NLTK_DIR", "/usr/local/share/nltk_data")
 
 TRASH_DIR = os.getenv("PAPERLESS_TRASH_DIR")
 
@@ -1031,7 +1029,7 @@ FILENAME_FORMAT_REMOVE_NONE = __get_boolean(
 
 THUMBNAIL_FONT_NAME = os.getenv(
     "PAPERLESS_THUMBNAIL_FONT_NAME",
-    "/usr/share/fonts/liberation/LiberationSerif-Regular.ttf",
+    "/usr/local/share/fonts/Liberation/LiberationSerif-Regular.ttf",
 )
 
 # Tika settings
