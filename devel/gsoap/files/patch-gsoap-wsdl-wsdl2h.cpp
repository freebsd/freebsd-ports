--- gsoap/wsdl/wsdl2h.cpp.orig
+++ gsoap/wsdl/wsdl2h.cpp
@@ -85,7 +85,7 @@ char *infile[MAXINFILES],
      *proxy_host = NULL,
      *proxy_userid = NULL,
      *proxy_passwd = NULL;
-extern const char
+const char
      *mapfile = WSDL_TYPEMAP_FILE,
      *import_path = WSDL2H_IMPORT_PATH,
      *cwd_path = NULL,
@@ -118,7 +118,7 @@ const char serviceformat[]             = "//gsoap %-4s service %s:\t%s %s\n";
 const char paraformat[]                = "    %-35s%s%s%s";
 const char anonformat[]                = "    %-35s%s_%s%s";
 
-const char copyrightnotice[] = "\n**  The gSOAP WSDL/Schema processor for C and C++, wsdl2h release "WSDL2H_VERSION"\n**  Copyright (C) 2000-2012 Robert van Engelen, Genivia Inc.\n**  All Rights Reserved. This product is provided \"as is\", without any warranty.\n**  The wsdl2h tool is released under one of the following two licenses:\n**  GPL or the commercial license by Genivia Inc. Use option -l for details.\n\n";
+const char copyrightnotice[] = "\n**  The gSOAP WSDL/Schema processor for C and C++, wsdl2h release " WSDL2H_VERSION "\n**  Copyright (C) 2000-2012 Robert van Engelen, Genivia Inc.\n**  All Rights Reserved. This product is provided \"as is\", without any warranty.\n**  The wsdl2h tool is released under one of the following two licenses:\n**  GPL or the commercial license by Genivia Inc. Use option -l for details.\n\n";
 
 const char licensenotice[]   = "\
 --------------------------------------------------------------------------------\n\
