--- ide/lazbuild.lpr	2018-07-28 08:38:06.000000000 -0500
+++ ide/lazbuild.lpr	2020-11-19 20:38:27.421396000 -0500
@@ -372,7 +372,7 @@
   if not FileExistsUTF8(Filename) then
   begin
     // Check for packages if the specified name is a valid identifier
-    if LazIsValidIdent(OriginalFileName) then begin
+    if PackageFileNameIsValid(OriginalFileName) then begin
       if PackageAction=lpaAddPkgLinks then begin
         Error(ErrorFileNotFound,'lpk file expected, but '+OriginalFilename+' found');
         Exit;
@@ -487,11 +487,10 @@
     XMLConfig.Free;
   end;
   // check Package Name
-  if (Result.Name='') or (not LazIsValidIdent(Result.Name)) then begin
+  if (Result.Name='') or (not IsValidPkgName(Result.Name)) then
     Error(ErrorPackageNameInvalid,
           Format(lisPkgMangThePackageNameOfTheFileIsInvalid,
                  [Result.Name, LineEnding, Result.Filename]));
-  end;
   // check if Package with same name is already loaded
   ConflictPkg:=PackageGraph.FindPackageWithName(Result.Name,nil);
   if ConflictPkg<>nil then begin
@@ -1051,7 +1050,7 @@
     PkgFilename:='';
     if CompareFileExt(PackageNamesOrFiles[i],'.lpk')=0 then
       PkgFilename:=ExpandFileNameUTF8(PackageNamesOrFiles[i])
-    else if LazIsValidIdent(PackageNamesOrFiles[i]) then begin
+    else if IsValidPkgName(PackageNamesOrFiles[i]) then begin
       PackageLink:=TLazPackageLink(LazPackageLinks.FindLinkWithPkgName(PackageNamesOrFiles[i]));
       if PackageLink=nil then
       begin
