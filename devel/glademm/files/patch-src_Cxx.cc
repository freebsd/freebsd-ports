--- src/Cxx.cc.orig	2018-08-26 06:39:26 UTC
+++ src/Cxx.cc
@@ -894,7 +894,7 @@ void Cxx::WriteCreation(SystemFile &f,File_type tp)
    if (!Configuration.author_email.empty())
       f << " by " << Configuration.author_email;
    f << '\n';
-   f << comment << " using "GLADEMM_NAME"\n";
+   f << comment << " using " GLADEMM_NAME "\n";
 }
 
 
