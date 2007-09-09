--- CUnit/Sources/Automated/Automated.c.orig	Wed Jul 25 09:07:09 2007
+++ CUnit/Sources/Automated/Automated.c	Wed Jul 25 16:45:43 2007
@@ -222,8 +222,8 @@
 
     fprintf(f_pTestResultFile,
             "<?xml version=\"1.0\" ?> \n"
-            "<?xml-stylesheet type=\"text/xsl\" href=\"CUnit-Run.xsl\" ?> \n"
-            "<!DOCTYPE CUNIT_TEST_RUN_REPORT SYSTEM \"CUnit-Run.dtd\"> \n"
+            "<?xml-stylesheet type=\"text/xsl\" href=\"/usr/local/share/CUnit/CUnit-Run.xsl\" ?> \n"
+            "<!DOCTYPE CUNIT_TEST_RUN_REPORT SYSTEM \"/usr/local/share/CUnit/CUnit-Run.dtd\"> \n"
             "<CUNIT_TEST_RUN_REPORT> \n"
             "  <CUNIT_HEADER/> \n");
   }
@@ -509,8 +509,8 @@
 
     fprintf(pTestListFile,
             "<?xml version=\"1.0\" ?> \n"
-            "<?xml-stylesheet type=\"text/xsl\" href=\"CUnit-List.xsl\" ?> \n"
-            "<!DOCTYPE CUNIT_TEST_LIST_REPORT SYSTEM \"CUnit-List.dtd\"> \n"
+            "<?xml-stylesheet type=\"text/xsl\" href=\"/usr/local/share/CUnit/CUnit-List.xsl\" ?> \n"
+            "<!DOCTYPE CUNIT_TEST_LIST_REPORT SYSTEM \"/usr/local/share/CUnit/CUnit-List.dtd\"> \n"
             "<CUNIT_TEST_LIST_REPORT> \n"
             "  <CUNIT_HEADER/> \n"
             "  <CUNIT_LIST_TOTAL_SUMMARY> \n");
