--- includes/regexp.php.orig	Sun Jul 24 12:00:47 2005
+++ includes/regexp.php	Wed Oct 26 23:03:01 2005
@@ -55,6 +55,20 @@
 
 };
 
+if (isset($_GET['sort2']) && !empty($_GET['sort2']))
+{
+    // Yes. Now check its regex format for safety -- Limited range
+    if (preg_match ("/^(asc|desc)$/", $_GET['sort2'])) {
+
+      // continue;
+    } else {
+
+      $fs->Redirect($fs->CreateURL('error', null));
+//         print "Sorting request is invalid."; exit;
+    };
+
+};
+
 if (isset($_GET['project']) && !empty($_GET['project'])) {
 
     // Yes. Now check its regex format for safety -- Numbers only
@@ -69,6 +83,21 @@
     };
 };
 
+if (isset($_GET['type']) && !empty($_GET['type'])) {
+
+    // Yes. Now check its regex format for safety -- Numbers only
+    if (preg_match ("/^\d+$/", $_GET['type'])) {
+
+      // continue;
+
+    } else {
+
+      $fs->Redirect($fs->CreateURL('error', null));
+//         print "Tasktype request is invalid."; exit;
+    };
+};
+
+
 if (isset($_GET['page']) && !empty($_GET['page']))
 {
     // Yes. Now check its regex format for safety -- Numbers only
@@ -324,4 +353,48 @@
 //         print "Magic URL is invalid."; exit;
     };
 };
+
+if (isset($_GET['tasks']) && !empty($_GET['tasks']))
+{
+    // Yes. Now check its regex format for safety -- Limited range
+    if (preg_match ("/^(all|assigned|reported|watched)$/", $_GET['tasks'])) {
+
+      // continue;
+    } else {
+
+      $fs->Redirect($fs->CreateURL('error', null));
+//         print "Tasks request is invalid."; exit;
+    };
+
+};
+
+if (isset($_GET['due']) && !empty($_GET['due'])) {
+
+    // Yes. Now check its regex format for safety -- Numbers only
+    if (preg_match ("/^\d+$/", $_GET['due'])) {
+
+       // continue;
+    } else {
+
+      $fs->Redirect($fs->CreateURL('error', null));
+//         print "Due version request is invalid."; exit;
+    };
+};
+
+if (isset($_GET['string']) && !empty($_GET['string'])) {
+
+    // Yes. Now check its regex format for safety -- Numbers only
+    if (preg_match ("!<.*>!", $_GET['string'])) {
+      $fs->Redirect($fs->CreateURL('error', null));
+    };
+};
+
+if (isset($_GET['PHPSESSID']) && !empty($_GET['PHPSESSID'])) {
+
+    // Yes. Now check its regex format for safety -- Numbers only
+    if (preg_match ("!<.*>!", $_GET['PHPSESSID'])) {
+      $fs->Redirect($fs->CreateURL('error', null));
+    };
+};
+
 ?>
