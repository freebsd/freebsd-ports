--- ext/bdb1/extconf.rb.orig	Fri Dec 27 22:32:58 2002
+++ ext/bdb1/extconf.rb	Sun Apr 27 05:35:25 2003
@@ -1,9 +1,10 @@
 #!/usr/bin/ruby
 require 'mkmf'
+require 'rbconfig'
 
-$stat_lib = if CONFIG.key?("LIBRUBYARG_STATIC")
+$stat_lib = if Config::CONFIG.key?("LIBRUBYARG_STATIC")
 	       $LDFLAGS += " -L#{CONFIG['libdir']}"
-	       CONFIG["LIBRUBYARG_STATIC"]
+	       Config::CONFIG["LIBRUBYARG_STATIC"]
 	    else
 	       "-lruby"
 	    end
@@ -40,8 +41,7 @@
 
 unknown: $(DLLIB)
 \t@echo "main() {}" > /tmp/a.c
-\t$(CC) -static /tmp/a.c $(OBJS) $(CPPFLAGS) $(DLDFLAGS) #$stat_lib #{CONFIG["LIBS"
-]} $(LIBS) $(LOCAL_LIBS)
+\t$(CC) -static /tmp/a.c $(OBJS) $(CPPFLAGS) $(DLDFLAGS) #$stat_lib #{Config::CONFIG["LIBS"]} $(LIBS) $(LOCAL_LIBS)
 \t@-rm /tmp/a.c a.out
 
 test: $(DLLIB)
