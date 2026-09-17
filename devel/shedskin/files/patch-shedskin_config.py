--- shedskin/config.py.orig	2026-09-17 22:22:58 UTC
+++ shedskin/config.py
@@ -701,6 +701,8 @@ def get_user_cache_dir() -> Path:
         return Path("~/Library/Caches/shedskin").expanduser()
     if PLATFORM == "Linux":
         return Path("~/.cache/shedskin").expanduser()
+    if PLATFORM == "FreeBSD":
+        return Path("~/.cache/shedskin").expanduser()
     if PLATFORM == "Windows":
         profile = os.getenv("USERPROFILE")
         if not profile:
