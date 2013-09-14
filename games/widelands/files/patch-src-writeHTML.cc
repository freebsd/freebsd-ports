--- src/writeHTML.cc.orig	2012-04-23 13:46:49.000000000 +0400
+++ src/writeHTML.cc	2013-09-13 22:31:32.367226376 +0400
@@ -223,7 +223,7 @@
 //  A container to keep the types ordered by descname for the table of
 // contents.
 struct orderer {
-	bool operator () (std::string const * const a, std::string const * const b)
+	bool operator () (std::string const * const a, std::string const * const b) const
 	{
 		return *a < *b;
 	}
