--- src/unix/unix.mak.orig	Mon Feb 14 18:08:49 2005
+++ src/unix/unix.mak	Mon Feb 14 18:09:12 2005
@@ -599,7 +599,7 @@
 	$(OBJDIR)/sysdep/rc.o \
 	$(OBJDIR)/tststubs.o
 	$(CC_COMMENT) @echo 'Linking $@...'
-	$(CC_COMPILE) $(LD) $(LDFLAGS) $(MY_LIBS) $^ -Wl,--allow-multiple-definition -o $@
+	touch $@
 
 $(OBJDIR)/tststubs.o: src/unix/tststubs.c
 	$(CC_COMPILE) $(CC) $(MY_CFLAGS) -o $@ -c $<
