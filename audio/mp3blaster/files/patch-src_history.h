
$FreeBSD$

--- src/history.h.orig	Sun Jul 21 13:54:56 2002
+++ src/history.h	Sun Jul 21 13:55:04 2002
@@ -21,7 +21,7 @@
 	const char *element();
 
 private:
-	vector<char *> v;
+	std::vector<char *> v;
 	unsigned int curpos;
 	std::vector<char *>::iterator it;
 };
