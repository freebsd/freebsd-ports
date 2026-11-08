-- Allow the pytest-based port test target to find the sample/test data
-- without using the unittest bootstrap CLI.  Read the locations from
-- environment variables set by the port Makefile.

--- opencv/modules/python/test/tests_common.py.orig	2025-07-04 16:37:46 UTC
+++ opencv/modules/python/test/tests_common.py
@@ -22,9 +22,9 @@
 class NewOpenCVTests(unittest.TestCase):

     # path to local repository folder containing 'samples' folder
-    repoPath = None
-    extraTestDataPath = None
-    extraDnnTestDataPath = None
+    repoPath = os.environ.get('OPENCV_TEST_REPO_PATH')
+    extraTestDataPath = os.environ.get('OPENCV_TEST_DATA_PATH')
+    extraDnnTestDataPath = os.environ.get('OPENCV_DNN_TEST_DATA_PATH')
     # github repository url
     repoUrl = 'https://raw.github.com/opencv/opencv/4.x'

