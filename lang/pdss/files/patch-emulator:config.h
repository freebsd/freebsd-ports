Index: emulator/config.h
===================================================================
RCS file: /ext/cvs/PDSS/emulator/config.h,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.1.2.1
diff -u -r1.1.1.1 -r1.1.1.1.2.1
--- emulator/config.h	11 Jun 2002 16:11:11 -0000	1.1.1.1
+++ emulator/config.h	20 Jul 2002 08:30:53 -0000	1.1.1.1.2.1
@@ -28,9 +28,12 @@
       object. It is uesd by dynamic native code module linker.
       (But, native code generator is not supported yet.)
 *************************************************************************/
-#define PDSS_LIBDIR      "/usr/local/src/pdss"
-#define PDSS_SUPDIR      "/usr/local/src/pdss/emulator"
-#define PDSS_OBJECT_FILE "/usr/local/src/pdss/emulator/pdss"
+/* #define PDSS_LIBDIR      "/usr/local/src/pdss" */
+#define PDSS_LIBDIR      "%%PREFIX%%/libexec/pdss"
+/* #define PDSS_SUPDIR      "/usr/local/src/pdss/emulator" */
+#define PDSS_SUPDIR      "%%PREFIX%%/libexec/pdss/emulator"
+/* #define PDSS_OBJECT_FILE "/usr/local/src/pdss/emulator/pdss" */
+#define PDSS_OBJECT_FILE "%%PREFIX%%/libexec/pdss/emulator/pdss"
 
 
 /*************************************************************************
@@ -69,8 +72,10 @@
       area at initial startup time, then PDSS divide code area into 2
       parts and use divided one for user codes.
 *************************************************************************/
-#define HEAP_SIZE  200000
-#define CODE_SIZE 1000000
+/* #define HEAP_SIZE  200000 */
+#define HEAP_SIZE  625000
+/* #define CODE_SIZE 1000000 */
+#define CODE_SIZE 5000000
 
 
 /*************************************************************************
@@ -169,7 +174,8 @@
 Configuration for atom table.
 >> MAX_ATOMS: Maximum number of atoms.
 *************************************************************************/
-#define MAX_ATOMS 20000
+/* #define MAX_ATOMS 20000 */
+#define MAX_ATOMS 50000
 
 
 /*************************************************************************
@@ -251,6 +257,9 @@
       INSTRUCTION_COUNT's value are `YES', PDSS counts the number of
       branches in each KL1-B instuction.
 *************************************************************************/
-#define INSTRUCTION_TRACE        NO
-#define INSTRUCTION_COUNT        NO
-#define INSTRUCTION_BRANCH_COUNT NO
+/* #define INSTRUCTION_TRACE        NO */
+#define INSTRUCTION_TRACE        YES
+/* #define INSTRUCTION_COUNT        NO */
+#define INSTRUCTION_COUNT        YES
+/* #define INSTRUCTION_BRANCH_COUNT NO */
+#define INSTRUCTION_BRANCH_COUNT YES
