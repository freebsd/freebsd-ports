commit a2b111bb09485769d75addf563cb6e44be6655b3
Author: James Turner <zakalawe@mac.com>
Date:   Wed Dec 14 09:41:44 2016 +0000

    Bugfix: reject dubious paths in HTTP repos.
    
    This avoids a malicious repository writing to files outside the local
    storage root.

diff --git simgear/io/HTTPRepository.cxx simgear/io/HTTPRepository.cxx
index 1c95f278..b0335783 100644
--- simgear/io/HTTPRepository.cxx
+++ simgear/io/HTTPRepository.cxx
@@ -503,6 +503,14 @@ private:
                 SG_LOG(SG_TERRASYNC, SG_WARN, "malformed .dirindex file: invalid type in line '" << line << "', expected 'd' or 'f', (ignoring line)" );
                 continue;
             }
+
+            // security: prevent writing outside the repository via ../../.. filenames
+            // (valid filenames never contain / - subdirectories have their own .dirindex)
+            if ((tokens[1] == "..") || (tokens[1].find_first_of("/\\") != std::string::npos)) {
+                SG_LOG(SG_TERRASYNC, SG_WARN, "malformed .dirindex file: invalid filename in line '" << line << "', (ignoring line)" );
+                continue;
+            }
+
             children.push_back(ChildInfo(typeData == "f" ? ChildInfo::FileType : ChildInfo::DirectoryType, tokens[1], tokens[2]));
 
             if (tokens.size() > 3) {
