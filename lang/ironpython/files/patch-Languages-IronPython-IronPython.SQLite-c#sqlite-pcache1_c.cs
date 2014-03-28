--- Languages/IronPython/IronPython.SQLite/c#sqlite/pcache1_c.cs.orig	2014-02-28 08:17:32.000000000 +0100
+++ Languages/IronPython/IronPython.SQLite/c#sqlite/pcache1_c.cs	2014-02-28 08:17:57.000000000 +0100
@@ -705,7 +705,7 @@
     static sqlite3_pcache pcache1Create( int szPage, bool bPurgeable )
     {
       PCache1 pCache;      /* The newly created page cache */
-      PGroup pGroup;       /* The group the new page cache will belong to */
+      PGroup pGroup = null;       /* The group the new page cache will belong to */
       int sz;               /* Bytes of memory required to allocate the new cache */
 
       /*
