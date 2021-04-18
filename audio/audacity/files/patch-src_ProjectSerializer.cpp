--- src/ProjectSerializer.cpp.orig	2021-02-04 18:52:51 UTC
+++ src/ProjectSerializer.cpp
@@ -206,9 +206,9 @@ ProjectSerializer::ProjectSerializer(size_t allocSize)
    std::call_once(flag, []{
       // Just once per run, store header information in the unique static
       // dictionary that will be written into each project that is saved.
-      // Store the size of "wxChar" so we can convert during recovery in
-      // case the file is used on a system with a different character size.
-      char size = sizeof(wxChar);
+      // Store the size of "wxStringCharType" so we can convert during recovery
+      // in case the file is used on a system with a different character size.
+      char size = sizeof(wxStringCharType);
       mDict.AppendByte(FT_CharSize);
       mDict.AppendData(&size, 1);
    });
@@ -242,7 +242,7 @@ void ProjectSerializer::WriteAttr(const wxString & nam
    mBuffer.AppendByte(FT_String);
    WriteName(name);
 
-   const Length len = value.length() * sizeof(wxChar);
+   const Length len = value.length() * sizeof(wxStringCharType);
    WriteLength( mBuffer, len );
    mBuffer.AppendData(value.wx_str(), len);
 }
@@ -309,7 +309,7 @@ void ProjectSerializer::WriteData(const wxString & val
 {
    mBuffer.AppendByte(FT_Data);
 
-   Length len = value.length() * sizeof(wxChar);
+   Length len = value.length() * sizeof(wxStringCharType);
    WriteLength( mBuffer, len );
    mBuffer.AppendData(value.wx_str(), len);
 }
@@ -317,7 +317,7 @@ void ProjectSerializer::WriteData(const wxString & val
 void ProjectSerializer::Write(const wxString & value)
 {
    mBuffer.AppendByte(FT_Raw);
-   Length len = value.length() * sizeof(wxChar);
+   Length len = value.length() * sizeof(wxStringCharType);
    WriteLength( mBuffer, len );
    mBuffer.AppendData(value.wx_str(), len);
 }
@@ -334,7 +334,7 @@ void ProjectSerializer::WriteSubTree(const ProjectSeri
 
 void ProjectSerializer::WriteName(const wxString & name)
 {
-   wxASSERT(name.length() * sizeof(wxChar) <= SHRT_MAX);
+   wxASSERT(name.length() * sizeof(wxStringCharType) <= SHRT_MAX);
    UShort id;
 
    auto nameiter = mNames.find(name);
@@ -346,7 +346,7 @@ void ProjectSerializer::WriteName(const wxString & nam
    {
       // mNames is static.  This appends each name to static mDict only once
       // in each run.
-      UShort len = name.length() * sizeof(wxChar);
+      UShort len = name.length() * sizeof(wxStringCharType);
 
       id = mNames.size();
       mNames[name] = id;
