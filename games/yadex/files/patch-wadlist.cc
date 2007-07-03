--- src/wadlist.cc.orig	Fri Mar 28 18:37:32 2003
+++ src/wadlist.cc	Tue Jul  3 18:35:21 2007
@@ -175,7 +175,8 @@
   priv->iter = priv->list.erase (i);
   if (priv->iter == priv->list.begin ())
   {
-    priv->iter = 0;			// Catch bugs
+    list_t::iterator empty;
+    priv->iter = empty;			// Catch bugs
     priv->rewound = true;
   }
 }
