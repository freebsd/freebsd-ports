--- zcav.cpp.orig	2012-11-23 07:26:19 UTC
+++ zcav.cpp
@@ -15,9 +15,7 @@ void usage()
        , "Usage: zcav [-b block-size[:chunk-size]] [-c count]\n"
          "            [-r [start offset:]end offset] [-w]\n"
          "            [-u uid-to-use:gid-to-use] [-g gid-to-use]\n"
-#ifdef _LARGEFILE64_SOURCE
          "            [-s skip rate]\n"
-#endif
          "            [-l log-file] [-f] file-name\n"
          "            [-l log-file [-f] file-name]...\n"
          "\n"
@@ -186,9 +184,7 @@ int main(int argc, char *argv[])
   const char *log = "-";
   const char *file = "";
   while(-1 != (c = getopt(argc, argv, "-c:b:f:l:r:w"
-#ifdef _LARGEFILE64_SOURCE
 				     "s:"
-#endif
                                      "u:g:")) )
   {
     switch(char(c))
@@ -225,11 +221,9 @@ int main(int argc, char *argv[])
         }
       }
       break;
-#ifdef _LARGEFILE64_SOURCE
       case 's':
         mz.setSkipRate(atoi(optarg));
       break;
-#endif
       case 'g':
         if(groupName)
           usage();
