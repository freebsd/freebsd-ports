--- Makefile.inc	Wed Mar  3 23:02:39 2004
+++ Makefile.inc	Thu Mar 11 18:59:19 2004
@@ -10,7 +10,7 @@
 	$(CC) -o $@ $^ $(LIBS) -shared
 
 $(OBJDIR)/%.o: %.c
-	$(CC) -c -o $@ $(CFLAGS) $<
+	$(CC) -c -o $@ $(CFLAGS) $< 
 
 $(DEPDIR)/%.d: %.c
 	$(CC) -MM $(CFLAGS) $< | sed "s/^$*\.o:/$(OBJDIR)\/$*\.o $(DEPDIR)\/$*\.d:/" > $@
