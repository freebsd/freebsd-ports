Fix i386 build: time_t is 32-bit there, so "return { _date + delta }"
narrows int64_t to time_t inside a braced-init-list, which clang rejects
with -Wc++11-narrowing (an error, not a warning).  Cast explicitly like
the operator+= / operator-= below already do.

--- src/libshared/src/Datetime.cpp.orig	2026-07-18 21:00:05 UTC
+++ src/libshared/src/Datetime.cpp
@@ -3818,13 +3818,13 @@
 ////////////////////////////////////////////////////////////////////////////////
 Datetime Datetime::operator+ (const int64_t delta)
 {
-  return { _date + delta };
+  return { (time_t) (_date + delta) };
 }
 
 ////////////////////////////////////////////////////////////////////////////////
 Datetime Datetime::operator- (const int64_t delta)
 {
-  return { _date - delta };
+  return { (time_t) (_date - delta) };
 }
 
 ////////////////////////////////////////////////////////////////////////////////
