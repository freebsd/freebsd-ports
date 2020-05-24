From: Damjan Jovanovic <damjan.jov@gmail.com>
Subject: [PATCH] libwine: Fix a regression in the return value check for mmap() on FreeBSD
Message-Id: <CAJm2B-=eV0e12Dw7mODFf5An=USGa-3bHhvLLDFsj2kDWsiyJw@mail.gmail.com>
Date: Sat, 23 May 2020 11:01:49 +0200

This fixes a regression from my previous patch in commit
55ba3648379d90642f174e74809b84130d6d1ddc, which was
checking for mmap() returning NULL instead of MAP_FAILED.

Wine-Bug: https://bugs.winehq.org/show_bug.cgi?id=49225
Signed-off-by: Damjan Jovanovic <damjan.jov@gmail.com>

--- UTC
diff --git a/libs/wine/mmap.c b/libs/wine/mmap.c
index 0fbe2efea7..af91b3e352 100644
--- libs/wine/mmap.c
+++ libs/wine/mmap.c
@@ -215,7 +215,7 @@ void *wine_anon_mmap( void *start, size_t size, int prot, int flags )
         /* If available, this will attempt a fixed mapping in-kernel */
         flags |= MAP_TRYFIXED;
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-        if ( start && mmap( start, size, prot, flags | MAP_FIXED | MAP_EXCL, get_fdzero(), 0 ) )
+        if ( start && mmap( start, size, prot, flags | MAP_FIXED | MAP_EXCL, get_fdzero(), 0 ) != MAP_FAILED )
             return start;
 #elif defined(__svr4__) || defined(__NetBSD__) || defined(__APPLE__)
         if ( try_mmap_fixed( start, size, prot, flags, get_fdzero(), 0 ) )

