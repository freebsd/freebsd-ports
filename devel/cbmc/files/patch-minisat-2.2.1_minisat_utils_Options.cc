--- minisat-2.2.1/minisat/utils/Options.cc.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/utils/Options.cc
@@ -43,10 +43,12 @@ void Minisat::parseOptions(int& argc, char** argv, boo
             }
 
             if (!parsed_ok)
+            {
                 if (strict && match(argv[i], "-"))
                     fprintf(stderr, "ERROR! Unknown flag \"%s\". Use '--%shelp' for help.\n", argv[i], Option::getHelpPrefixString()), exit(1);
                 else
                     argv[j++] = argv[i];
+            }
         }
     }
 
