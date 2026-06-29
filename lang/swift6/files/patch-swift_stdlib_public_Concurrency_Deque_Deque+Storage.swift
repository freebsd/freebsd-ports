--- swift/stdlib/public/Concurrency/Deque/Deque+Storage.swift.orig	2026-01-28 03:14:51 UTC
+++ swift/stdlib/public/Concurrency/Deque/Deque+Storage.swift
@@ -131,6 +131,8 @@ extension _Deque._Storage {
   /// insertion.
   internal static var growthFactor: Double { 1.5 }
 
+  @_optimize(none)
+  @inline(never)
   internal func _growCapacity(
     to minimumCapacity: Int,
     linearly: Bool
