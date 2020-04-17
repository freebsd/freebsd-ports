--- sonic-visualiser.pro.orig	2020-04-16 19:10:53 UTC
+++ sonic-visualiser.pro
@@ -8,11 +8,11 @@ SUBDIRS += \
 # writing they are only automatically run on non-Windows platforms
 # (because of the difficulty of getting them running nicely in the
 # IDE without causing great confusion if a test fails).
-SUBDIRS += \
-        sub_test_svcore_base \
-        sub_test_svcore_system \
-        sub_test_svcore_data_fileio \
-        sub_test_svcore_data_model
+#SUBDIRS += \
+#        sub_test_svcore_base \
+#        sub_test_svcore_system \
+#        sub_test_svcore_data_fileio \
+#        sub_test_svcore_data_model
 
 SUBDIRS += \
 	checker \
@@ -22,10 +22,10 @@ SUBDIRS += \
 
 sub_base.file = base.pro
         
-sub_test_svcore_base.file = test-svcore-base.pro
-sub_test_svcore_system.file = test-svcore-system.pro
-sub_test_svcore_data_fileio.file = test-svcore-data-fileio.pro
-sub_test_svcore_data_model.file = test-svcore-data-model.pro
+#sub_test_svcore_base.file = test-svcore-base.pro
+#sub_test_svcore_system.file = test-svcore-system.pro
+#sub_test_svcore_data_fileio.file = test-svcore-data-fileio.pro
+#sub_test_svcore_data_model.file = test-svcore-data-model.pro
 
 sub_server.file = server.pro
 sub_convert.file = convert.pro
