--- swiftpm/Sources/Basics/Vendor/Triple.swift.orig	2024-06-05 06:47:24 UTC
+++ swiftpm/Sources/Basics/Vendor/Triple.swift
@@ -1089,7 +1089,7 @@ extension Triple {
     case cloudABI = "cloudabi"
     case darwin
     case dragonFly = "dragonfly"
-    case freeBSD = "freebsd"
+    case freebsd
     case fuchsia
     case ios
     case kfreebsd
@@ -1137,7 +1137,7 @@ extension Triple {
       case _ where os.hasPrefix("dragonfly"):
         return .dragonFly
       case _ where os.hasPrefix("freebsd"):
-        return .freeBSD
+        return .freebsd
       case _ where os.hasPrefix("fuchsia"):
         return .fuchsia
       case _ where os.hasPrefix("ios"):
