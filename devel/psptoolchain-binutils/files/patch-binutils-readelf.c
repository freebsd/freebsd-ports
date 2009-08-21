--- binutils/readelf.c.orig	2005-04-20 19:43:36.000000000 +0100
+++ binutils/readelf.c	2006-05-09 02:55:36.000000000 +0100
@@ -2043,6 +2043,7 @@
 	    case E_MIPS_MACH_5500: strcat (buf, ", 5500"); break;
 	    case E_MIPS_MACH_SB1:  strcat (buf, ", sb1");  break;
 	    case E_MIPS_MACH_9000: strcat (buf, ", 9000"); break;
+	    case E_MIPS_MACH_ALLEGREX: strcat (buf, ", allegrex"); break;
 	    case 0:
 	    /* We simply ignore the field in this case to avoid confusion:
 	       MIPS ELF does not specify EF_MIPS_MACH, it is a GNU
