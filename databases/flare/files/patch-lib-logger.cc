--- src/lib/logger.cc.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/lib/logger.cc	2010-05-29 10:05:44.216154429 +0900
@@ -69,7 +69,7 @@
  */
 void logger::emerg(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][EMG][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][EMG][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
@@ -85,7 +85,7 @@
  */
 void logger::alert(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][ALT][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][ALT][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
@@ -101,7 +101,7 @@
  */
 void logger::crit(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][CRT][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][CRT][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
@@ -117,7 +117,7 @@
  */
 void logger::err(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][ERR][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][ERR][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
@@ -133,7 +133,7 @@
  */
 void logger::warning(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][WRN][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][WRN][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
@@ -149,7 +149,7 @@
  */
 void logger::notice(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][NTC][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][NTC][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
@@ -165,7 +165,7 @@
  */
 void logger::info(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][INF][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][INF][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
@@ -181,7 +181,7 @@
  */
 void logger::debug(const char* file, const int line, const char* func, const char *format, ...) {
 	ostringstream s;
-	s << "[" << (unsigned int)pthread_self() << "][DBG][" << file << ":" << line << "-" << func << "] ";
+	s << "[" << (unsigned long)pthread_self() << "][DBG][" << file << ":" << line << "-" << func << "] ";
 
 	char buf[1024];
 	va_list op;
