--- src/libs/sqlite/sqlitebasestatement.h.orig	2024-10-30 22:45:51 UTC
+++ src/libs/sqlite/sqlitebasestatement.h
@@ -412,9 +412,7 @@ class StatementImplementation : public BaseStatement (
         BaseSqliteResultRange(BaseSqliteResultRange &) = delete;
         BaseSqliteResultRange &operator=(BaseSqliteResultRange &) = delete;
 
-        BaseSqliteResultRange(BaseSqliteResultRange &&other)
-            : m_statement{std::move(other.resetter)}
-        {}
+        BaseSqliteResultRange(BaseSqliteResultRange &&other) = delete;
         BaseSqliteResultRange &operator=(BaseSqliteResultRange &&) = delete;
 
         iterator begin() & { return iterator{m_statement}; }
