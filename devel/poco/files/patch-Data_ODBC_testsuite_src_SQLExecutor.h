--- Data/ODBC/testsuite/src/SQLExecutor.h.orig	2024-10-20 02:54:30 UTC
+++ Data/ODBC/testsuite/src/SQLExecutor.h
@@ -236,8 +236,8 @@ class SQLExecutor: public CppUnit::TestCase (public)
 		assert (size - 1 == ints.back());
 		assert (std::string("xyz0") == strings.front());
 		assert (std::string("xyz") + number == strings.back());
-		assert (CLOB("abc0") == blobs.front());
-		CLOB blob("abc");
+		assert (CLOB(std::string("abc0")) == blobs.front());
+		CLOB blob(std::string("abc"));
 		blob.appendRaw(number.c_str(), number.size());
 		assert (blob == blobs.back());
 		assert (.5 == floats.front());
@@ -289,7 +289,7 @@ class SQLExecutor: public CppUnit::TestCase (public)
 		assert (size - 1 == ints.back());
 		assert (std::string("xyz0") == strings.front());
 		assert (std::string("xyz") + number == strings.back());
-		assert (CLOB("abc0") == blobs.front());
+		assert (CLOB(std::string("abc0")) == blobs.front());
 		blob.assignRaw("abc", 3);
 		blob.appendRaw(number.c_str(), number.size());
 		assert (blob == blobs.back());
@@ -371,8 +371,8 @@ class SQLExecutor: public CppUnit::TestCase (public)
 		assert (size - 1 == ints.back());
 		assert (std::string("xyz0") == strings.front());
 		assert (std::string("xyz") + number == strings.back());
-		assert (CLOB("abc0") == blobs.front());
-		CLOB blob("abc");
+		assert (CLOB(std::string("abc0")) == blobs.front());
+		CLOB blob(std::string("abc"));
 		blob.appendRaw(number.c_str(), number.size());
 		assert (blob == blobs.back());
 		assert (.5 == floats.front());
@@ -417,7 +417,7 @@ class SQLExecutor: public CppUnit::TestCase (public)
 		assert (size - 1 == ints.back());
 		assert (std::string("xyz0") == strings.front());
 		assert (std::string("xyz") + number == strings.back());
-		assert (CLOB("abc0") == blobs.front());
+		assert (CLOB(std::string("abc0")) == blobs.front());
 		blob.assignRaw("abc", 3);
 		blob.appendRaw(number.c_str(), number.size());
 		assert (blob == blobs.back());
