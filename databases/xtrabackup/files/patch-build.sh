--- utils/build.sh	2013-05-22 19:00:32.000000000 +0200
+++ utils/build.sh	2013-07-02 21:36:25.534672963 +0200
@@ -281,6 +281,7 @@
                 -DWITH_EXTRA_CHARSETS=all \
                 -DWITH_EMBEDDED_SERVER=1 \
                 -DENABLE_DTRACE=OFF $extra_config_55plus"
+        export LIBS=-lcrypt
         build_all $type
         ;;
 
@@ -316,9 +317,14 @@
 	    bzr revert
 	    bzr pull --overwrite
 	else
-	    bzr branch -r tag:Percona-Server-$PS_51_VERSION \
-		lp:percona-server/5.1 $branch_dir
+	    #bzr branch -r tag:Percona-Server-$PS_51_VERSION \
+	#	lp:percona-server/5.1 $branch_dir
+	    tar -xvzf Percona-Server-${PS_51_VERSION}-patches.tar.gz
+	    ln -sf Percona-Server-${PS_51_VERSION}-patches $branch_dir
+	    ln  mysql-${MYSQL_51_VERSION}.tar.gz $branch_dir
 	    cd $branch_dir
+	    #fix for cmake, from https://bugs.launchpad.net/percona-xtradb/+bug/666223
+	    sed -i .orig 's/inline void _increment_page_get_statistics/void _increment_page_get_statistics/' patches/innodb_extend_slow.patch
 	fi
 
 	$MAKE_CMD main
@@ -370,9 +376,15 @@
 	    bzr revert
 	    bzr pull --overwrite
 	else
-	    bzr branch -r tag:Percona-Server-$PS_55_VERSION \
-		lp:percona-server $branch_dir
+#	    bzr branch -r tag:Percona-Server-$PS_55_VERSION \
+#		lp:percona-server $branch_dir
+	    tar -xvzf Percona-Server-${PS_55_VERSION}-patches.tar.gz
+	    ln -sf Percona-Server-${PS_55_VERSION}-patches $branch_dir
+	    ln mysql-5.5.16.tar.gz $branch_dir
 	    cd $branch_dir
+	    #fix for cmake, from https://bugs.launchpad.net/percona-xtradb/+bug/666223
+	    sed -i .orig 's/inline void _increment_page_get_statistics/void _increment_page_get_statistics/' patches/innodb_extend_slow.patch
+
 	fi
 
 	$MAKE_CMD PERCONA_SERVER=Percona-Server-5.5 main
