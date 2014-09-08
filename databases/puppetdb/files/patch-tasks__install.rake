--- tasks/install.rake.orig	2014-07-07 17:37:05.000000000 +0000
+++ tasks/install.rake	2014-09-01 19:42:02.500986018 +0000
@@ -14,24 +14,21 @@
   @osfamily = Facter.value(:osfamily).downcase
   mkdir_p "#{DESTDIR}/#{@install_dir}"
   mkdir_p "#{DESTDIR}/#{@config_dir}"
-  mkdir_p "#{DESTDIR}/#{@config_dir}/.."
   mkdir_p "#{DESTDIR}/#{@log_dir}"
-  mkdir_p "#{DESTDIR}/etc/init.d/"
+  unless @osfamily =~ /freebsd/
+    mkdir_p "#{DESTDIR}/etc/init.d/"
+  end
   mkdir_p "#{DESTDIR}/#{@lib_dir}"
   mkdir_p "#{DESTDIR}/#{@libexec_dir}"
   mkdir_p "#{DESTDIR}/#{@sbin_dir}"
-  mkdir_p "#{DESTDIR}/etc/logrotate.d/"
-  ln_sf @config_dir, "#{DESTDIR}/#{@lib_dir}/config"
-  ln_sf @log_dir, "#{DESTDIR}/#{@install_dir}/log"
+#  ln_sf @config_dir, "#{DESTDIR}/#{@lib_dir}/config"
+#  ln_sf @log_dir, "#{DESTDIR}/#{@install_dir}/log"
 
   unless @pe
-    mkdir_p "#{DESTDIR}/var/lib/puppetdb/state"
-    mkdir_p "#{DESTDIR}/var/lib/puppetdb/db"
-    mkdir_p "#{DESTDIR}/var/lib/puppetdb/mq"
-    ln_sf "#{@lib_dir}/state", "#{DESTDIR}#{@link}/state"
-    ln_sf "#{@lib_dir}/db", "#{DESTDIR}#{@link}/db"
-    ln_sf "#{@lib_dir}/mq", "#{DESTDIR}#{@link}/mq"
-    mkdir_p "#{DESTDIR}/etc/puppetdb"
+    mkdir_p "#{DESTDIR}#{@lib_dir}/state"
+    mkdir_p "#{DESTDIR}#{@lib_dir}/db"
+    mkdir_p "#{DESTDIR}#{@lib_dir}/mq"
+    mkdir_p "#{DESTDIR}#{@etc_dir}"
   else
     mkdir_p "#{DESTDIR}#{@lib_dir}/state"
     mkdir_p "#{DESTDIR}#{@lib_dir}/db"
@@ -40,11 +37,11 @@
   end
 
   cp_p JAR_FILE, "#{DESTDIR}/#{@install_dir}"
-  cp_pr "ext/files/config.ini", "#{DESTDIR}/#{@config_dir}"
-  cp_pr "ext/files/database.ini", "#{DESTDIR}/#{@config_dir}"
-  cp_pr "ext/files/jetty.ini", "#{DESTDIR}/#{@config_dir}"
-  cp_pr "ext/files/repl.ini", "#{DESTDIR}/#{@config_dir}"
-  cp_pr "ext/files/puppetdb.logrotate", "#{DESTDIR}/etc/logrotate.d/#{@name}"
+  cp_pr "ext/files/config.ini", "#{DESTDIR}/#{@config_dir}/config.ini.sample"
+  cp_pr "ext/files/database.ini", "#{DESTDIR}/#{@config_dir}/database.ini.sample"
+  cp_pr "ext/files/jetty.ini", "#{DESTDIR}/#{@config_dir}/jetty.ini.sample"
+  cp_pr "ext/files/repl.ini", "#{DESTDIR}/#{@config_dir}/repl.ini.sample"
+  cp_pr "ext/files/puppetdb.newsyslog", "#{DESTDIR}%%PREFIX%%/etc/newsyslog.conf.d/#{@name}"
   cp_pr "ext/files/logback.xml", "#{DESTDIR}/#{@config_dir}/.."
   cp_pr "ext/files/puppetdb", "#{DESTDIR}/#{@sbin_dir}"
 
@@ -100,6 +97,11 @@
     cp_p "ext/files/puppetdb.openbsd.init", "#{DESTDIR}/etc/rc.d/#{@name}.rc"
     cp_p "ext/files/puppetdb.env", "#{DESTDIR}/#{@libexec_dir}/#{@name}.env"
     chmod 0755, "#{DESTDIR}/etc/rc.d/#{@name}.rc"
+  elsif @osfamily == "freebsd"
+    #mkdir_p "#{DESTDIR}/etc/rc.d/"
+    #cp_p "ext/files/puppetdb.openbsd.init", "#{DESTDIR}/etc/rc.d/#{@name}.rc"
+    #cp_p "ext/files/puppetdb.env", "#{DESTDIR}/#{@libexec_dir}/#{@name}.env"
+    #chmod 0755, "#{DESTDIR}/etc/rc.d/#{@name}.rc"
   elsif @osfamily == "archlinux"
     #systemd!
     mkdir_p "#{DESTDIR}/etc/sysconfig"
@@ -113,10 +115,5 @@
   end
   chmod 0750, "#{DESTDIR}/#{@config_dir}"
   chmod 0640, "#{DESTDIR}/#{@config_dir}/../logback.xml"
-  chmod 0700, "#{DESTDIR}/#{@sbin_dir}/puppetdb-ssl-setup"
-  chmod 0700, "#{DESTDIR}/#{@sbin_dir}/puppetdb-foreground"
-  chmod 0700, "#{DESTDIR}/#{@sbin_dir}/puppetdb-import"
-  chmod 0700, "#{DESTDIR}/#{@sbin_dir}/puppetdb-export"
-  chmod 0700, "#{DESTDIR}/#{@sbin_dir}/puppetdb-anonymize"
   chmod 0700, "#{DESTDIR}/#{@sbin_dir}/puppetdb"
 end
