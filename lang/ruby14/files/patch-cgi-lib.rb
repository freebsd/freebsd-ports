--- lib/cgi-lib.rb.orig	Tue Oct 12 18:11:29 1999
+++ lib/cgi-lib.rb	Mon Aug 21 04:26:56 2000
@@ -121,30 +121,40 @@
   RFC822_MONTHS = %w[ Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec ]
 
   # make rfc1123 date string
-  def rfc1123_date(time)
+  def CGI.rfc1123_date(time)
     t = time.clone.gmtime
     return format("%s, %.2d %s %d %.2d:%.2d:%.2d GMT",
                 RFC822_DAYS[t.wday], t.day, RFC822_MONTHS[t.month-1], t.year,
                 t.hour, t.min, t.sec)
   end
+  def rfc1123_date(time)
+    CGI.rfc1123_date(time)
+  end
 
   # escape url encode
-  def escape(str)
+  def CGI.escape(str)
     str.gsub(/[^a-zA-Z0-9_\-.]/n){ sprintf("%%%02X", $&.unpack("C")[0]) }
   end
+  def escape(str)
+    CGI.escape(str)
+  end
 
   # unescape url encoded
-  def unescape(str)
+  def CGI.unescape(str)
     str.gsub(/\+/, ' ').gsub(/%([0-9a-fA-F]{2})/){ [$1.hex].pack("c") }
   end
+  def unescape(str)
+    CGI.unescape(str)
+  end
 
   # escape HTML
-  def escapeHTML(str)
+  def CGI.escapeHTML(str)
     str.gsub(/&/, "&amp;").gsub(/\"/, "&quot;").gsub(/>/, "&gt;").gsub(/</, "&lt;")
   end
-
-  module_function :escape, :unescape, :escapeHTML, :rfc1123_date
-
+  def escapeHTML(str)
+    CGI.escapeHTML(str)
+  end
+	
   # offline mode. read name=value pairs on standard input.
   def read_from_cmdline
     require "shellwords.rb"
