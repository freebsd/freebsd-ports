--- ./binutils/readelf.c.orig	2011-09-21 20:49:13.000000000 +0000
+++ ./binutils/readelf.c	2012-01-21 13:31:35.000000000 +0000
@@ -2395,10 +2395,11 @@
 	    case E_MIPS_MACH_9000: strcat (buf, ", 9000"); break;
   	    case E_MIPS_MACH_LS2E: strcat (buf, ", loongson-2e"); break;
   	    case E_MIPS_MACH_LS2F: strcat (buf, ", loongson-2f"); break;
-  	    case E_MIPS_MACH_LS3A: strcat (buf, ", loongson-3a"); break;
+  	    /* case E_MIPS_MACH_LS3A: strcat (buf, ", loongson-3a"); break; */
 	    case E_MIPS_MACH_OCTEON: strcat (buf, ", octeon"); break;
 	    case E_MIPS_MACH_OCTEON2: strcat (buf, ", octeon2"); break;
 	    case E_MIPS_MACH_XLR:  strcat (buf, ", xlr"); break;
+	    case E_MIPS_MACH_ALLEGREX: strcat(buf, ", allegrex"); break;
 	    case 0:
 	    /* We simply ignore the field in this case to avoid confusion:
 	       MIPS ELF does not specify EF_MIPS_MACH, it is a GNU
