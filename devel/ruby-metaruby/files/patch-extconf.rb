--- extconf.rb.orig	Tue Sep 18 11:03:21 2001
+++ extconf.rb	Tue Sep 18 18:10:04 2001
@@ -34,18 +34,18 @@
 	f.puts
 
 	f.puts "install::"
-	f.puts "\t@mkdir $(DESTDIR)/Hollow $(DESTDIR)/lgram || true"
+	f.puts "\t@mkdir -p $(DESTDIR)/Hollow $(DESTDIR)/lgram"
 	FILES1.each {|fn1|
 		fn2 = fn1
-		f.puts "\tinstall --mode 644 #{fn2} $(DESTDIR)/#{fn2}"
+		f.puts "\tinstall -m 644 #{fn2} $(DESTDIR)/#{fn2}"
 	}
 	FILES2.each {|fn1|
 		fn2 = "Hollow/#{fn1}"
-		f.puts "\tinstall --mode 644 #{fn2} $(DESTDIR)/#{fn2}"
+		f.puts "\tinstall -m 644 #{fn2} $(DESTDIR)/#{fn2}"
 	}
 	FILES3.each {|fn1|
 		fn2 = "lgram/#{fn1}"
-		f.puts "\tinstall --mode 644 #{fn2} $(DESTDIR)/#{fn2}"
+		f.puts "\tinstall -m 644 #{fn2} $(DESTDIR)/#{fn2}"
 	}
 }
 
