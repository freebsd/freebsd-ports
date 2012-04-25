--- CUnit/Sources/Automated/Automated.c.orig	2009-06-11 03:50:52.000000000 +0900
+++ CUnit/Sources/Automated/Automated.c	2012-04-14 02:08:39.000000000 +0900
@@ -227,13 +227,13 @@
     if (bJUnitXmlOutput == CU_TRUE) {
         fprintf(f_pTestResultFile,
             "<?xml version=\"1.0\" ?> \n"
-            "<?xml-stylesheet type=\"text/xsl\" href=\"CUnit-Run.xsl\" ?> \n"
+            "<?xml-stylesheet type=\"text/xsl\" href=\"/usr/local/share/CUnit/CUnit-Run.xsl\" ?> \n"
             "  <cunit_testsuites> \n");
     } else {
         fprintf(f_pTestResultFile,
             "<?xml version=\"1.0\" ?> \n"
-            "<?xml-stylesheet type=\"text/xsl\" href=\"CUnit-Run.xsl\" ?> \n"
-            "<!DOCTYPE CUNIT_TEST_RUN_REPORT SYSTEM \"CUnit-Run.dtd\"> \n"
+            "<?xml-stylesheet type=\"text/xsl\" href=\"/usr/local/share/CUnit/CUnit-Run.xsl\" ?> \n"
+            "<!DOCTYPE CUNIT_TEST_RUN_REPORT SYSTEM \"/usr/local/share/CUnit/CUnit-Run.dtd\"> \n"
             "<CUNIT_TEST_RUN_REPORT> \n"
             "  <CUNIT_HEADER/> \n");
     }
@@ -616,8 +616,8 @@
         
         fprintf(pTestListFile,
             "<?xml version=\"1.0\" ?> \n"
-            "<?xml-stylesheet type=\"text/xsl\" href=\"CUnit-List.xsl\" ?> \n"
-            "<!DOCTYPE CUNIT_TEST_LIST_REPORT SYSTEM \"CUnit-List.dtd\"> \n"
+            "<?xml-stylesheet type=\"text/xsl\" href=\"/usr/local/share/CUnit/CUnit-List.xsl\" ?> \n"
+            "<!DOCTYPE CUNIT_TEST_LIST_REPORT SYSTEM \"/usr/local/share/CUnit/CUnit-List.dtd\"> \n"
             "<CUNIT_TEST_LIST_REPORT> \n"
             "  <CUNIT_HEADER/> \n"
             "  <CUNIT_LIST_TOTAL_SUMMARY> \n");
