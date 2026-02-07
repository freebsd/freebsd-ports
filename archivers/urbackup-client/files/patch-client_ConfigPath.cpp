Build fails on FreeBSD due to a casting error from the wxString Class when using
wx30-gtk2-3.0.4_1. This patch adds a cast (static_cast<const wchar_t*>) that
resolves the error.

--- client/ConfigPath.cpp.orig	2022-08-29 17:43:41 UTC
+++ client/ConfigPath.cpp
@@ -208,7 +208,7 @@ void ConfigPath::OnClickNew(wxCommandEvent &evt)
 		listbox->Append(ed.GetPath() );
 		SBackupDir ad;
 		ad.path=ed.GetPath();
-		ad.name=getDefaultDirname(ad.path.wc_str());
+		ad.name=getDefaultDirname(static_cast<const wchar_t*>(ad.path.wc_str()));
 		ad.group=0;
 		ad.id=0;
 		ad.server_default = 0;
