--- src/glade--.cc.orig	2018-08-26 06:40:08 UTC
+++ src/glade--.cc
@@ -393,7 +393,7 @@ int main(int argc,char **argv)
       	 break;
       case 'h': Configuration.header_suffix=optarg;
          break;
-      case 'V': std::cout<< "glademm V"VERSION" (glade to Gtk-- converter)\n";
+      case 'V': std::cout<< "glademm V" VERSION " (glade to Gtk-- converter)\n";
          return 0;
          break;
       case 'v': Configuration.verbose++; break;
@@ -487,7 +487,7 @@ int main(int argc,char **argv)
 		 "\t--baseclass\tderive from base class (for class parameters)\n"
          	 "\t--libglade\tgenerate code skeleton for a libglade-- application.\n"
          	 "\t--libglade-option\tgenerate infrastructure for libglade without using it.\n"
-         	 "\t--version\tprints 'glademm V"VERSION"'\n";
+         	 "\t--version\tprints 'glademm V" VERSION "'\n";
          return 1;
    }
    if (argc-optind!=1) goto usage;
