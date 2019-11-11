--- src/mongo/base/error_codes.tpl.h.orig	2019-08-13 23:47:34 UTC
+++ src/mongo/base/error_codes.tpl.h
@@ -118,7 +118,7 @@ template <int32_t code>
 constexpr bool isNamedCode = false;
 //#for $ec in $codes
 template <>
-constexpr bool isNamedCode<ErrorCodes::$ec.name> = true;
+constexpr inline bool isNamedCode<ErrorCodes::$ec.name> = true;
 //#end for
 
 MONGO_COMPILER_NORETURN void throwExceptionForStatus(const Status& status);
