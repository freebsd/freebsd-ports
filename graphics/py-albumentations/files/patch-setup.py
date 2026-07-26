-- fix stage_fs_violations that tis causes

--- setup.py.orig2025-05-27 17:47:03 UTC
+++ setup.py
@@ -32,22 +32,8 @@ def is_installed(package_name: str) -> bool:
 def choose_opencv_requirement():
     """Check if any OpenCV package is already installed and use that one."""
     # First try to import cv2 to see if any OpenCV is installed
-    try:
-        import cv2
-
-        # Try to determine which package provides the installed cv2
-        for package in OPENCV_PACKAGES:
-            package_name = re.split(r"[!<>=]", package)[0].strip()
-            if is_installed(package_name):
-                return package
-
-        # If we can import cv2 but can't determine the package,
-        # don't add any OpenCV requirement
-        return None
-
-    except ImportError:
-        # No OpenCV installed, use the headless version as default
-        return f"opencv-python-headless>={MIN_OPENCV_VERSION}"
+    # On FreeBSD, opencv is provided by graphics/opencv, skip dynamic detection
+    return None
 
 
 # Read the long description from README
