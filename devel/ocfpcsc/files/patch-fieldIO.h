--- fieldIO.h	2009-01-07 17:34:35.118522599 +0100
+++ fieldIO.h	2009-01-07 17:34:39.651535899 +0100
@@ -55,7 +55,7 @@
  * != 0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long getIntField(JNIEnv *, jobject,  char *, long *);
+long getIntField(JNIEnv *, jobject,  const char *, long *);
 
 
 /*******************************************************************************
@@ -75,7 +75,7 @@
  * != 0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long setIntField(JNIEnv *, jobject,  char *, long);
+long setIntField(JNIEnv *, jobject,  const char *, long);
 
 
 /*******************************************************************************
@@ -99,7 +99,7 @@
  * != 0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long accessByteArray(JNIEnv *, jobject, char *, unsigned char **, int *);
+long accessByteArray(JNIEnv *, jobject, const char *, unsigned char **, int *);
 
 
 /*******************************************************************************
@@ -120,7 +120,7 @@
  * !=0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long releaseByteArray(JNIEnv *, jobject,  char *, unsigned char *);
+long releaseByteArray(JNIEnv *, jobject,  const char *, unsigned char *);
 
 
 /*******************************************************************************
@@ -141,7 +141,7 @@
  * NULL		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-const char *accessStringField(JNIEnv *, jobject,  char *);
+const char *accessStringField(JNIEnv *, jobject,  const char *);
 
 
 /*******************************************************************************
@@ -160,5 +160,5 @@
  * != 0		  - problem occurred, exception was thrown
  *
  ******************************************************************************/
-long releaseStringField(JNIEnv *, jobject,  char *, const char *);
+long releaseStringField(JNIEnv *, jobject,  const char *, const char *);
 
