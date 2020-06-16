# based on: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=245976#c12
# https://jira.mongodb.org/browse/SERVER-44025
# https://github.com/mongodb/mongo/commit/e484c9af6b4ae4a1d22c905e252ad3ad13f30bfc
--- src/mongo/base/error_codes.tpl.h.orig	2020-06-07 14:38:05 UTC
+++ src/mongo/base/error_codes.tpl.h
@@ -127,7 +127,7 @@ template <int32_t code>
 constexpr bool isNamedCode = false;
 //#for $ec in $codes
 template <>
-constexpr bool isNamedCode<ErrorCodes::$ec.name> = true;
+constexpr inline bool isNamedCode<ErrorCodes::$ec.name> = true;
 //#end for
 
 MONGO_COMPILER_NORETURN void throwExceptionForStatus(const Status& status);
