--- installer.rb.orig	Mon Nov 17 18:59:32 2003
+++ installer.rb	Tue Dec  2 00:46:09 2003
@@ -55,16 +55,19 @@
 	ENV['DOCDIR'    ] ||= "#{ENV['PREFIX']}/share/doc"
 	ENV['ETCDIR'    ] ||= "#{ENV['PREFIX']}/etc"
 	ENV['CGIDIR'    ] ||= "#{ENV['LIBEXEC']}/#{ENV['PROGNAME']}/cgi-bin"
+	ENV['WWWDIR'    ] ||= "#{ENV['PREFIX']}/www"
 
 	ENV['VERSION'	] ||= VERSION
 
 	@installdir    = "#{ENV['LIBEXEC']}/#{ENV['PROGNAME']}"
 	@confdir       = "#{ENV['ETCDIR']}/#{ENV['PROGNAME']}#{ENV['ETCDIST']}"
 	@zc            = "#{@installdir}/zc/zc.rb"
+	@wwwdir    = "#{ENV['WWWDIR']}/#{ENV['PROGNAME']}"
 
 	@ch_installdir = "#{ENV['CHROOT']}#{@installdir}"
 	@ch_confdir    = "#{ENV['CHROOT']}#{@confdir}"
 	@ch_zc         = "#{ENV['CHROOT']}#{@zc}"
+	@ch_wwwdir = "#{ENV['CHROOT']}#{@wwwdir}"
 
 	@verbose       = true
     end
@@ -185,7 +188,8 @@
 
     def inst_cgi
 	puts "==> Installing HTML pages"
-	cp_r "www", @ch_installdir,			:verbose => @verbose
+	mkdir_p	@ch_wwwdir,				:verbose => @verbose
+	cp_r "www", @ch_wwwdir,			:verbose => @verbose
 	puts
 
 	puts "==> Installing CGI"
