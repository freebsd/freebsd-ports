--- binutils-gdb--gdb/gdbsupport/enum-flags.h.orig	2024-11-30 00:01:16 UTC
+++ binutils-gdb--gdb/gdbsupport/enum-flags.h
@@ -75,30 +75,6 @@
    namespace.  The compiler finds the corresponding
    is_enum_flags_enum_type function via ADL.  */
 
-/* Note that std::underlying_type<enum_type> is not what we want here,
-   since that returns unsigned int even when the enum decays to signed
-   int.  */
-template<int size, bool sign> class integer_for_size { typedef void type; };
-template<> struct integer_for_size<1, 0> { typedef uint8_t type; };
-template<> struct integer_for_size<2, 0> { typedef uint16_t type; };
-template<> struct integer_for_size<4, 0> { typedef uint32_t type; };
-template<> struct integer_for_size<8, 0> { typedef uint64_t type; };
-template<> struct integer_for_size<1, 1> { typedef int8_t type; };
-template<> struct integer_for_size<2, 1> { typedef int16_t type; };
-template<> struct integer_for_size<4, 1> { typedef int32_t type; };
-template<> struct integer_for_size<8, 1> { typedef int64_t type; };
-
-template<typename T>
-struct enum_underlying_type
-{
-  DIAGNOSTIC_PUSH
-  DIAGNOSTIC_IGNORE_ENUM_CONSTEXPR_CONVERSION
-  typedef typename
-    integer_for_size<sizeof (T), static_cast<bool>(T (-1) < T (0))>::type
-    type;
-  DIAGNOSTIC_POP
-};
-
 namespace enum_flags_detail
 {
 
@@ -119,11 +95,62 @@ using EnumIsUnsigned
 /* gdb::Requires trait helpers.  */
 template <typename enum_type>
 using EnumIsUnsigned
-  = std::is_unsigned<typename enum_underlying_type<enum_type>::type>;
+  = std::is_unsigned<typename std::underlying_type<enum_type>::type>;
+
+/* Helper to detect whether an enum has a fixed underlying type. This can be
+   achieved by using a scoped enum (in which case the type is "int") or
+   an explicit underlying type. C-style enums that are unscoped or do not
+   have an explicit underlying type have an implementation-defined underlying
+   type.
+
+   https://timsong-cpp.github.io/cppwp/n4659/dcl.enum#5
+
+   We need this trait in order to ensure that operator~ below does NOT
+   operate on old-style enums. This is because we apply operator~ on
+   the value and then cast the result to the enum_type. This is however
+   Undefined Behavior if the result does not fit in the range of possible
+   values for the enum. For enums with fixed underlying type, the entire
+   range of the integer is available. However, for old-style enums, the range
+   is only the smallest bit-field that can hold all the values of the
+   enumeration, typically much smaller than the underlying integer:
+
+   https://timsong-cpp.github.io/cppwp/n4659/expr.static.cast#10
+   https://timsong-cpp.github.io/cppwp/n4659/dcl.enum#8
+
+   To implement this, we leverage the fact that, since C++17, enums with
+   fixed underlying type can be list-initialized from an integer:
+   https://timsong-cpp.github.io/cppwp/n4659/dcl.init.list#3.7
+
+   Old-style enums cannot be initialized like that, leading to ill-formed
+   code.
+
+   We then use this together with SFINAE to create the desired trait.
+
+*/
+template <typename enum_type, typename = void>
+struct EnumHasFixedUnderlyingType : std::false_type
+{
+  static_assert(std::is_enum<enum_type>::value);
+};
+
+/* Specialization that is active only if enum_type can be
+   list-initialized from an integer (0).  Only enums with fixed
+   underlying type satisfy this property in C++17.  */
 template <typename enum_type>
-using EnumIsSigned
-  = std::is_signed<typename enum_underlying_type<enum_type>::type>;
+struct EnumHasFixedUnderlyingType<enum_type, std::void_t<decltype(enum_type{0})>> : std::true_type
+{
+  static_assert(std::is_enum<enum_type>::value);
+};
 
+template <typename enum_type>
+using EnumIsSafeForBitwiseComplement = std::conjunction<
+  EnumIsUnsigned<enum_type>,
+  EnumHasFixedUnderlyingType<enum_type>
+>;
+
+template <typename enum_type>
+using EnumIsUnsafeForBitwiseComplement = std::negation<EnumIsSafeForBitwiseComplement<enum_type>>;
+
 }
 
 template <typename E>
@@ -131,7 +158,7 @@ class enum_flags (public)
 {
 public:
   typedef E enum_type;
-  typedef typename enum_underlying_type<enum_type>::type underlying_type;
+  typedef typename std::underlying_type<enum_type>::type underlying_type;
 
   /* For to_string.  Maps one enumerator of E to a string.  */
   struct string_mapping
@@ -394,33 +421,41 @@ template <typename enum_type,
 template <typename enum_type,
 	  typename = is_enum_flags_enum_type_t<enum_type>,
 	  typename
-	    = gdb::Requires<enum_flags_detail::EnumIsUnsigned<enum_type>>>
+	    = gdb::Requires<enum_flags_detail::EnumIsSafeForBitwiseComplement<enum_type>>>
 constexpr enum_type
 operator~ (enum_type e)
 {
   using underlying = typename enum_flags<enum_type>::underlying_type;
-  return (enum_type) ~underlying (e);
+  /* Cast to ULONGEST first, to prevent integer promotions from enums
+     with fixed underlying type std::uint8_t or std::uint16_t to
+     signed int.  This ensures we apply the bitwise complement on an
+     unsigned type.  */
+  return (enum_type)(underlying) ~ULONGEST (e);
 }
 
 template <typename enum_type,
 	  typename = is_enum_flags_enum_type_t<enum_type>,
-	  typename = gdb::Requires<enum_flags_detail::EnumIsSigned<enum_type>>>
+	  typename = gdb::Requires<enum_flags_detail::EnumIsUnsafeForBitwiseComplement<enum_type>>>
 constexpr void operator~ (enum_type e) = delete;
 
 template <typename enum_type,
 	  typename = is_enum_flags_enum_type_t<enum_type>,
 	  typename
-	    = gdb::Requires<enum_flags_detail::EnumIsUnsigned<enum_type>>>
+	    = gdb::Requires<enum_flags_detail::EnumIsSafeForBitwiseComplement<enum_type>>>
 constexpr enum_flags<enum_type>
 operator~ (enum_flags<enum_type> e)
 {
   using underlying = typename enum_flags<enum_type>::underlying_type;
-  return (enum_type) ~underlying (e);
+  /* Cast to ULONGEST first, to prevent integer promotions from enums
+     with fixed underlying type std::uint8_t or std::uint16_t to
+     signed int.  This ensures we apply the bitwise complement on an
+     unsigned type.  */
+  return (enum_type)(underlying) ~ULONGEST (e);
 }
 
 template <typename enum_type,
 	  typename = is_enum_flags_enum_type_t<enum_type>,
-	  typename = gdb::Requires<enum_flags_detail::EnumIsSigned<enum_type>>>
+	  typename = gdb::Requires<enum_flags_detail::EnumIsUnsafeForBitwiseComplement<enum_type>>>
 constexpr void operator~ (enum_flags<enum_type> e) = delete;
 
 /* Delete operator<< and operator>>.  */
