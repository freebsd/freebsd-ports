
$FreeBSD$

--- cftypes.cpp	2002/10/01 11:38:22	1.1
+++ cftypes.cpp	2002/10/01 11:39:37
@@ -10,7 +10,7 @@
 #ifndef __CFTYPES_CPP__
 #define __CFTYPES_CPP__
 
-#include <values.h>
+#include <limits.h>
 #include <fstream.h>
 #include "zlib.h"
 #include "cftypes.h"
@@ -138,12 +138,12 @@
 
 int io_read(istream& in, byte* buf, word len)
 {
-	while(len > MAXINT)
+	while(len > INT_MAX)
 	{
-		if(in.read(buf, MAXINT).bad())
+		if(in.read(buf, INT_MAX).bad())
 			return (in.fail()) ? READ_ERROR : UNEXPECTED_EOF;
-		len -= (word) MAXINT;
-		buf += (word) MAXINT;
+		len -= (word) INT_MAX;
+		buf += (word) INT_MAX;
 	}
 
 	return (in.read(buf, (int) len).bad())
@@ -154,11 +154,11 @@
 
 int io_write(ostream& out, const byte* buf, word len)
 {
-	while(len > MAXINT)
+	while(len > INT_MAX)
 	{
-		if(out.write(buf, MAXINT).fail()) return WRITE_ERROR;
-		len -= (word) MAXINT;
-		buf += (word) MAXINT;
+		if(out.write(buf, INT_MAX).fail()) return WRITE_ERROR;
+		len -= (word) INT_MAX;
+		buf += (word) INT_MAX;
 	}
 
 	return (out.write(buf, (int) len).fail()) ? WRITE_ERROR : OK;
