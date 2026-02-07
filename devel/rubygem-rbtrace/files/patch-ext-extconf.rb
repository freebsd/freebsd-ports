--- ext/extconf.rb.orig	2019-10-31 16:57:02 UTC
+++ ext/extconf.rb
@@ -41,6 +41,8 @@ unless File.exists?("#{CWD}/dst/#{libdir}/libmsgpackc.
       puts "  -- env CFLAGS=#{ENV['CFLAGS'].inspect} LDFLAGS=#{ENV['LDFLAGS'].inspect} CC=#{ENV['CC'].inspect}"
       sys("./configure --disable-dependency-tracking --disable-shared --with-pic --prefix=#{CWD}/dst/ --libdir=#{CWD}/dst/#{libdir}")
       sys("make install")
+      FileUtils.rm "#{CWD}/src/#{dir}/src/.libs/libmsgpackc.la"
+      FileUtils.rm "#{CWD}/src/#{dir}/src/.libs/libmsgpack.la"
     end
   end
 
