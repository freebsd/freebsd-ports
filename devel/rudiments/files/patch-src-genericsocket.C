--- src/genericsocket.C.orig	Mon Apr 15 11:21:24 2002
+++ src/genericsocket.C	Tue Oct 28 08:10:37 2003
@@ -211,7 +211,7 @@
 				// If we got no error, just didn't get
 				// all of the data, we need to get the
 				// rest.
-				return retval+safeRead(fd,buf+retval,
+				return retval+safeRead(fd,(char *)buf+retval,
 							realcount-retval);
 			} else if (errno && showerrors) {
 				cerr << "error: read failed: ";
@@ -223,7 +223,7 @@
 
 	// handle cases where count>SSIZE_MAX by continuing to read
 	if (realcount<count) {
-		return retval+safeRead(fd,buf+retval,count-retval);
+		return retval+safeRead(fd,(char *)buf+retval,count-retval);
 	}
 
 	return retval;
@@ -260,7 +260,7 @@
 
 	// must send at least 1 iovector with 1 byte of real data
 	struct iovec	iovector[1];
-	iovector[0].iov_base=(void *)" ";
+	iovector[0].iov_base=const_cast<char *>(" ");
 	iovector[0].iov_len=sizeof(char);
 	messageheader.msg_iov=iovector;
 	messageheader.msg_iovlen=1;
