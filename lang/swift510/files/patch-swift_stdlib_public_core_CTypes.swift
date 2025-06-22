--- swift/stdlib/public/core/CTypes.swift.orig	2024-06-06 04:26:30 UTC
+++ swift/stdlib/public/core/CTypes.swift
@@ -106,6 +106,9 @@ public typealias CLongDouble = Float80
 #elseif os(FreeBSD)
 #if arch(x86_64) || arch(i386)
 public typealias CLongDouble = Float80
+#elseif arch(arm64)
+// FreeBSD on arm64 uses 128-bit floating point type for 'long double'.
+// Swift doesn't have Float128 yet so we don't define CLongDouble.
 #else
 #error("CLongDouble needs to be defined for this FreeBSD architecture")
 #endif
