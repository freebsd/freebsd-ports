--- compiler/systems/t_bsd.pas	2012-04-22 14:47:06.000000000 -0500
+++ compiler/systems/t_bsd.pas	2013-10-01 21:07:10.000000000 -0500
@@ -484,10 +484,19 @@
   if linklibc and
      not IsDarwin Then
    begin
-     if librarysearchpath.FindFile('crtbegin.o',false,s) then
-      LinkRes.AddFileName(s);
      if librarysearchpath.FindFile('crti.o',false,s) then
       LinkRes.AddFileName(s);
+     if cs_create_pic in current_settings.moduleswitches then
+       begin
+         if librarysearchpath.FindFile('crtbeginS.o',false,s) then
+           LinkRes.AddFileName(s);
+       end
+       else
+         if (cs_link_staticflag in current_settings.globalswitches) and
+           librarysearchpath.FindFile('crtbeginT.o',false,s) then
+             LinkRes.AddFileName(s)
+         else if librarysearchpath.FindFile('crtbegin.o',false,s) then
+             LinkRes.AddFileName(s);
    end;
   { main objectfiles }
   while not ObjectFiles.Empty do
@@ -572,7 +581,10 @@
   if linklibc and
      not IsDarwin Then
    begin
-     Fl1:=librarysearchpath.FindFile('crtend.o',false,s1);
+     if cs_create_pic in current_settings.moduleswitches then
+       Fl1:=librarysearchpath.FindFile('crtendS.o',false,s1)
+     else
+       Fl1:=librarysearchpath.FindFile('crtend.o',false,s1);
      Fl2:=librarysearchpath.FindFile('crtn.o',false,s2);
      if Fl1 or Fl2 then
       begin
