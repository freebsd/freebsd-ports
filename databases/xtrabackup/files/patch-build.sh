--- utils/build.sh	2012-02-10 15:54:51.000000000 +0100
+++ utils/build.sh	2012-03-16 20:53:58.366366222 +0100
@@ -225,9 +225,14 @@
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
@@ -283,9 +288,15 @@
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
