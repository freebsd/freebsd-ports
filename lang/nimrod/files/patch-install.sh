--- install.sh.orig
+++ install.sh
@@ -15,39 +15,14 @@
     "--help"|"-h"|"help"|"h")
       echo "Nimrod installation script"
       echo "Usage: [sudo] sh install.sh DIR"
-      echo "Where DIR may be:"
-      echo "  /usr/bin"
-      echo "  /usr/local/bin"
-      echo "  /opt"
-      echo "  <some other dir> (treated like '/opt')"
-      echo "To deinstall, use the command:"
-      echo "sh deinstall.sh DIR"
       exit 1
       ;;
-    "/usr/bin")
-      bindir=/usr/bin
-      configdir=/etc
-      libdir=/usr/lib/nimrod
-      docdir=/usr/share/nimrod/doc
-      datadir=/usr/share/nimrod/data
-      ;;
-    "/usr/local/bin")
-      bindir=/usr/local/bin
-      configdir=/etc
-      libdir=/usr/local/lib/nimrod
-      docdir=/usr/local/share/nimrod/doc
-      datadir=/usr/local/share/nimrod/data
-      ;;
     *)
-      bindir="$1/nimrod/bin"
-      configdir="$1/nimrod/config"
-      libdir="$1/nimrod/lib"
-      docdir="$1/nimrod/doc"
-      datadir="$1/nimrod/data"
-      
-      mkdir -p $1/nimrod
-      mkdir -p $bindir
-      mkdir -p $configdir
+      bindir=$1/bin
+      configdir=$1/etc
+      libdir=$1/lib/nimrod
+      docdir=$1/share/doc/nimrod
+      datadir=$1/share/nimrod
       ;;
   esac
   mkdir -p $libdir
