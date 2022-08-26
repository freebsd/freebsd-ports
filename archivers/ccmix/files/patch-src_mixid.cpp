From c55a16f2a142c55f344480c3eecc6ecdedcfa735 Mon Sep 17 00:00:00 2001
From: askeladdk <askeladdk@users.noreply.github.com>
Date: Sat, 2 Jan 2016 14:15:35 +0100
Subject: [PATCH] The filenames of unidentified files will be used as the
 internal ID without being re-hashed. This lets you repack
 unidentified files easily. Unidentified filenames are
 detected if their name is exactly 8 characters long and
 does not contain a dot ('.').

--- src/mixid.cpp.orig	2017-06-12 14:07:35 UTC
+++ src/mixid.cpp
@@ -8,7 +8,7 @@ namespace MixID 
 {
     namespace
     {
-        int32_t crc_table[256] = {
+        uint32_t crc_table[256] = {
             0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
             0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988, 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
             0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
@@ -42,8 +42,6 @@ namespace MixID 
             0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
             0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94, 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d};
         
-        const char* marker = "[id]";
-        
         uint32_t do_block(const void* data, int size);
         
         uint32_t do_block(const void* data, int size)
@@ -62,7 +60,7 @@ namespace MixID 
     {
         //if the filename starts [id] treat next 8 chars as an id to convert to int
         if(isIdName(fname)){
-            return strId(fname.substr(4, 8));
+            return strId(fname);
         }
         std::transform(fname.begin(), fname.end(), fname.begin(),
                 (int(*)(int)) toupper); // convert to uppercase
@@ -128,6 +126,6 @@ namespace MixID 
     
     bool isIdName(std::string fname)
     {
-        return !strncmp(fname.c_str(), marker, strlen(marker));
+        return (fname.size() == 8) && (fname.find('.') == std::string::npos);
     }
 }
