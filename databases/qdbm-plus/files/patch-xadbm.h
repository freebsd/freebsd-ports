--- xadbm.h.orig	2006-01-01 05:23:58 UTC
+++ xadbm.h
@@ -72,21 +72,21 @@ private:
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
 
 
 
