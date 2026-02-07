Avoid the following build error on i386:

ld: error: undefined symbol: _GLOBAL_OFFSET_TABLE_
>>> referenced by mulodi4.c:19 (/usr/src/contrib/llvm-project/compiler-rt/lib/builtins/mulodi4.c:19)
>>>               mulodi4.o:(__mulodi4) in archive /usr/lib/libgcc.a

--- src/core/overflowsafe_type.hpp.orig	2021-10-17 09:31:25 UTC
+++ src/core/overflowsafe_type.hpp
@@ -112,7 +112,7 @@ class OverflowSafeInt (public)
 	 */
 	inline constexpr OverflowSafeInt& operator *= (const int factor)
 	{
-#ifdef HAS_OVERFLOW_BUILTINS
+#if defined(HAS_OVERFLOW_BUILTINS) && !defined(__i386__)
 		const bool is_result_positive = (this->m_value < 0) == (factor < 0); // -ve * -ve == +ve
 		if (unlikely(__builtin_mul_overflow(this->m_value, factor, &this->m_value))) {
 			this->m_value = is_result_positive ? T_MAX : T_MIN;
