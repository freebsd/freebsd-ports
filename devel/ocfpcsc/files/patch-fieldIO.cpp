--- fieldIO.cpp.orig	2009-01-07 17:34:29.486504988 +0100
+++ fieldIO.cpp	2009-01-07 17:34:39.651535899 +0100
@@ -58,7 +58,7 @@
  * != 0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long getIntField(JNIEnv *env, jobject obj,  char *fieldName, long *pFieldValue) {
+long getIntField(JNIEnv *env, jobject obj,  const char *fieldName, long *pFieldValue) {
    long   rc = 1;
    jfieldID fid;
 
@@ -92,7 +92,7 @@
  * != 0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long setIntField(JNIEnv *env, jobject obj,  char *fieldName, long fieldValue) {
+long setIntField(JNIEnv *env, jobject obj,  const char *fieldName, long fieldValue) {
    long   rc = 1;
    jfieldID fid;
 
@@ -132,7 +132,7 @@
  ******************************************************************************/
 long accessByteArray(JNIEnv *env,
 		    jobject obj,
-		    char *fieldName,
+		    const char *fieldName,
 		    unsigned char **field,
 		    int *pSize) {
 
@@ -182,7 +182,7 @@
  * !=0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long releaseByteArray(JNIEnv *env, jobject obj,  char *fieldName, unsigned char *pByte) {
+long releaseByteArray(JNIEnv *env, jobject obj,  const char *fieldName, unsigned char *pByte) {
 
    long	       rc=1;
    jfieldID    fid;
@@ -225,7 +225,7 @@
  * NULL		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-const char *accessStringField(JNIEnv *env, jobject obj,  char *fieldName) {
+const char *accessStringField(JNIEnv *env, jobject obj,  const char *fieldName) {
    jfieldID    fid;
    jstring     jstr;
    const char  *pstr = NULL;
@@ -261,7 +261,7 @@
  * != 0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long releaseStringField(JNIEnv *env, jobject obj,  char *fieldName, const char *field) {
+long releaseStringField(JNIEnv *env, jobject obj,  const char *fieldName, const char *field) {
    jfieldID    fid;
    jstring     jstr;
    int	       error = 1;
