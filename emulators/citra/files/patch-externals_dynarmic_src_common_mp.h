std::tuple_element_t appeared in FreeBSD 10.2 (libcxx r202673) but
USES=compiler cannot pull newer C++14-compatible libc++ version.

  In file included from externals/dynarmic/src/frontend/disassembler/disassembler_arm.cpp:15:
  In file included from externals/dynarmic/src/./frontend/decoder/arm.h:18:
  In file included from externals/dynarmic/src/./frontend/decoder/decoder_detail.h:14:
  externals/dynarmic/src/./common/mp.h:34:27: fatal error: no template named 'tuple_element_t' in namespace 'std'; did you mean 'tuple_element'?
	  using type = std::tuple_element_t<ParameterIndex, std::tuple<Args...>>;
		       ~~~~~^~~~~~~~~~~~~~~
			    tuple_element
  /usr/include/c++/v1/__tuple:44:62: note: 'tuple_element' declared here
  template <size_t _Ip, class _Tp> class _LIBCPP_TYPE_VIS_ONLY tuple_element;
							       ^

--- externals/dynarmic/src/common/mp.h.orig	2016-09-14 22:03:09 UTC
+++ externals/dynarmic/src/common/mp.h
@@ -9,6 +9,17 @@
 #include <cstddef>
 #include <tuple>
 
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#  if defined(_LIBCPP_VERSION) && __FreeBSD_version < 1001508
+// Copied from <tuple>
+namespace std {
+    template <size_t _Ip, class ..._Tp>
+        using tuple_element_t = typename tuple_element <_Ip, _Tp...>::type;
+}
+#  endif
+#endif
+
 namespace Dynarmic {
 namespace mp {
 
