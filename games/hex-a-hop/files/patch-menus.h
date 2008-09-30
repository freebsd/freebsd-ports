--- menus.h.orig	2006-02-21 06:10:35.000000000 +0300
+++ menus.h	2008-09-14 21:34:41.711083734 +0400
@@ -1073,7 +1073,7 @@
 		if (under)
 			under->Render();
 
-		RenderFade(time, dir, (int)this);
+		RenderFade(time, dir, reinterpret_cast<intptr_t>(this));
 	}
 	void Update(double timedelta)
 	{
