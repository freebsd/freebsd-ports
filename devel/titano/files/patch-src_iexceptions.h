--- src/iexceptions.h.orig	Tue Sep 12 21:54:25 2000
+++ src/iexceptions.h	Thu Apr  7 17:37:27 2005
@@ -24,6 +24,8 @@
 #include <string>
 #include <string.h>
 
+using namespace std;
+
 class Exception : public exception
 {
 protected:
@@ -33,6 +35,9 @@
 		message(msg)
 	{ };
 	
+	virtual ~Exception() throw()
+	{ };
+
 	virtual operator string()
 	{
 		return message;
@@ -51,6 +56,9 @@
 		error(err)
 	{ };
 
+	virtual ~EIOError() throw()
+	{ };
+
 	virtual operator string()
 	{
 		return message + "\n" +
@@ -71,6 +79,9 @@
 		reason(reas)
 	{ };
 
+	virtual ~ENotSupported() throw()
+	{ };
+
 	virtual operator string()
 	{
 		return message + "\n" +
@@ -91,6 +102,9 @@
 		error(err)
 	{ };
 
+	virtual ~EShellError() throw()
+	{ };
+
 	virtual operator string()
 	{
 		return message + "\n" +
