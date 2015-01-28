--- xadbm.h.orig	2006-01-01 08:23:58.000000000 +0300
+++ xadbm.h	2015-01-28 23:44:53.000000000 +0300
@@ -72,21 +72,21 @@
  * @param latter the latter datum.
  * @return reference to a temporary instance.
  */
-qdbm::Datum qdbm::operator +(const qdbm::Datum& former, const qdbm::Datum& latter);
+//qdbm::Datum qdbm::operator +(const qdbm::Datum& former, const qdbm::Datum& latter);
 /**
  * Temporary concatenation operator for Datum.
  * @param datum the former datum.
  * @param str the latter string.
  * @return reference to a temporary instance.
  */
-qdbm::Datum qdbm::operator +(const qdbm::Datum& datum, const char* str);
+//qdbm::Datum qdbm::operator +(const qdbm::Datum& datum, const char* str);
 /**
  * Temporary concatenation operator for Datum.
  * @param str the former string.
  * @param datum the latter datum.
  * @return reference to a temporary instance.
  */
-qdbm::Datum qdbm::operator +(const char* str, const qdbm::Datum& datum);
+//qdbm::Datum qdbm::operator +(const char* str, const qdbm::Datum& datum);
 
 
 
