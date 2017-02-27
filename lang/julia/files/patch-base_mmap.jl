--- base/mmap.jl.orig	2017-02-23 09:50:38 UTC
+++ base/mmap.jl
@@ -27,7 +27,7 @@ const PROT_READ     = Cint(1)
 const PROT_WRITE    = Cint(2)
 const MAP_SHARED    = Cint(1)
 const MAP_PRIVATE   = Cint(2)
-const MAP_ANONYMOUS = Cint(is_apple() ? 0x1000 : 0x20)
+const MAP_ANONYMOUS = Cint(0x1000)
 const F_GETFL       = Cint(3)
 
 gethandle(io::IO) = fd(io)
