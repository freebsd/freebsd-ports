--- platforms/unix/src/plugins/UnixOSProcessPlugin/UnixOSProcessPlugin.c.org	Sun Apr 23 16:18:27 2006
+++ platforms/unix/src/plugins/UnixOSProcessPlugin/UnixOSProcessPlugin.c	Sun Apr 23 16:20:43 2006
@@ -1818,7 +1818,7 @@
 		return interpreterProxy->primitiveFail();
 	}
 	sqFile = interpreterProxy->arrayValueOf(sqFileOop);
-	if ((feof(sqFile->file)) == 0) {
+	if ((feof((FILE *)sqFile->file)) == 0) {
 		result = interpreterProxy->falseObject();
 	} else {
 		result = interpreterProxy->trueObject();
@@ -1870,7 +1870,7 @@
 
 	/* Set up the flock structure parameter for fcntl() */
 
-	fileNo = fileno(sqFile->file);
+	fileNo = fileno((FILE *)sqFile->file);
 	if (exclusive) {
 		lockStruct.l_type = F_WRLCK;
 	} else {
@@ -2897,7 +2897,7 @@
 
 	/* Set up the flock structure parameter for fcntl() */
 
-	fileNo = fileno(sqFile->file);
+	fileNo = fileno((FILE *)sqFile->file);
 	if (exclusive) {
 		lockStruct.l_type = F_WRLCK;
 	} else {
@@ -2957,7 +2957,7 @@
 		return interpreterProxy->primitiveFail();
 	}
 	sqFile = interpreterProxy->arrayValueOf(sqFileOop);
-	fileNo = fileno(sqFile->file);
+	fileNo = fileno((FILE *)sqFile->file);
 	interpreterProxy->pop(2);
 	interpreterProxy->pushInteger(fileNo);
 }
@@ -3001,7 +3001,7 @@
 
 	/* Set up the flock structure parameter for fcntl() */
 
-	fileNo = fileno(sqFile->file);
+	fileNo = fileno((FILE *)sqFile->file);
 	lockStruct.l_type = F_UNLCK;
 	lockStruct.l_whence = SEEK_SET;
 	lockStruct.l_start = start;
