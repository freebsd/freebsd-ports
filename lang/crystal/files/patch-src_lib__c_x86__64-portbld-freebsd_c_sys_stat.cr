--- src/lib_c/x86_64-portbld-freebsd/c/sys/stat.cr.orig	2017-10-27 14:50:57 UTC
+++ src/lib_c/x86_64-portbld-freebsd/c/sys/stat.cr
@@ -31,23 +31,40 @@ lib LibC
   struct Stat
     st_dev : DevT
     st_ino : InoT
-    st_mode : ModeT
-    st_nlink : NlinkT
+    {% if flag?(:"freebsd12.0") %}
+      st_nlink : NlinkT
+      st_mode : ModeT
+      st_pad0 : UShort
+    {% else %}
+      st_mode : ModeT
+      st_nlink : NlinkT
+    {% end %}
     st_uid : UidT
     st_gid : GidT
+    {% if flag?(:"freebsd12.0") %}
+      st_pad1 : UInt
+    {% end %}
     st_rdev : DevT
     st_atim : Timespec
     st_mtim : Timespec
     st_ctim : Timespec
+    {% if flag?(:"freebsd12.0") %}
+      st_birthtim : Timespec
+    {% end %}
     st_size : OffT
     st_blocks : BlkcntT
     st_blksize : BlksizeT
     st_flags : FflagsT
-    st_gen : UInt
-    st_lspare : Int
-    st_birthtim : Timespec
-    __reserved_17 : UInt
-    __reserved_18 : UInt
+    {% if flag?("freebsd12.0") %}
+      st_gen : ULong
+      st_spare : StaticArray(ULong, 10)
+    {% else %}
+      st_gen : UInt
+      st_lspare : Int
+      st_birthtim : Timespec
+      __reserved_17 : UInt
+      __reserved_18 : UInt
+    {% end %}
   end
 
   fun chmod(x0 : Char*, x1 : ModeT) : Int
