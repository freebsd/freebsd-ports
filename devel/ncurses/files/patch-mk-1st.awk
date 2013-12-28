--- ./mk-1st.awk.orig	2013-09-07 19:54:05.000000000 +0200
+++ ./mk-1st.awk	2013-12-28 11:51:10.000000000 +0100
@@ -487,7 +487,6 @@
 					symlink("libncurses.a", "libcurses.a")
 					printf ")\n"
 				}
-				printf "\t$(RANLIB) $(DESTDIR)$(libdir)/%s\n", lib_name
 				if ( host == "vxworks" )
 				{
 					printf "\t@echo installing ../lib/lib%s$o as $(DESTDIR)$(libdir)/lib%s$o\n", name, name
