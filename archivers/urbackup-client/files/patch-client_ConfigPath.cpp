Build fails on FreeBSD due to a casting error from the wxString Class when using
wx30-gtk2-3.0.4_1. This patch adds a cast (static_cast<const wchar_t*>) that 
resolves the error.

--- client/ConfigPath.cpp.orig	2018-08-09 00:18:20.807732000 +0000
+++ client/ConfigPath.cpp	2018-08-09 00:19:21.531197000 +0000
@@ -60,7 +60,7 @@
 		listbox->Append(dirs[i].path);
 		if(dirs[i].name.IsEmpty())
 		{
-			dirs[i].name=getDefaultDirname(dirs[i].path.wc_str());
+			dirs[i].name=getDefaultDirname(static_cast<const wchar_t*>(dirs[i].path.wc_str()));
 		}
 	}
 
@@ -93,7 +93,7 @@
 		listbox->Append(ed.GetPath() );
 		SBackupDir ad;
 		ad.path=ed.GetPath();
-		ad.name=getDefaultDirname(ad.path.wc_str());
+		ad.name=getDefaultDirname(static_cast<const wchar_t*>(ad.path.wc_str()));
 		ad.group=0;
 		ad.id=0;
 		dirs.push_back(ad);
