--- periodic/xPERIODICx_zfsnap.sh.orig	2020-07-28 02:17:05 UTC
+++ periodic/xPERIODICx_zfsnap.sh
@@ -11,23 +11,29 @@ fi
 
 # xPERIODICx_zfsnap_enable          - Enable xPERIODICx snapshots (values: YES | NO)
 # xPERIODICx_zfsnap_flags           - `zfsnap snapshot` flags
-# xPERIODICx_zfsnap_fs              - Space-separated ZFS filesystems to create non-recursive snapshots
-# xPERIODICx_zfsnap_recursive_fs    - Space-separated ZFS filesystems to create recursive snapshots
+# xPERIODICx_zfsnap_delete_flags    - `zfsnap destroy` flags
+# xPERIODICx_zfsnap_fs              - Space-separated ZFS filesystems to manage non-recursive snapshots
+# xPERIODICx_zfsnap_recursive_fs    - Space-separated ZFS filesystems to manage recursive snapshots
 # xPERIODICx_zfsnap_ttl             - Explicit TTL value
 # xPERIODICx_zfsnap_verbose         - Verbose output (values: YES | NO)
 # xPERIODICx_zfsnap_enable_prefix   - Create snapshots with prefix (values: YES | NO) (Default = YES)
 # xPERIODICx_zfsnap_prefix          - set prefix for snapshots (Default = xPERIODICx)
+# xPERIODICx_zfsnap_delete_prefixes - Space-separated list of prefixes of expired zfsnap snapshots to delete
 
 case "${xPERIODICx_zfsnap_enable-"NO"}" in
     [Yy][Ee][Ss])
-        OPTIONS="$xPERIODICx_zfsnap_flags"
+        CREATE_OPTIONS="$xPERIODICx_zfsnap_flags"
+        DESTROY_OPTIONS="$xPERIODICx_zfsnap_delete_flags"
 
         case "${xPERIODICx_zfsnap_verbose-"NO"}" in
-            [Yy][Ee][Ss]) OPTIONS="$OPTIONS -v" ;;
+            [Yy][Ee][Ss])
+                CREATE_OPTIONS="$CREATE_OPTIONS -v"
+                DESTROY_OPTIONS="$DESTROY_OPTIONS -v"
+            ;;
         esac
 
         case "${xPERIODICx_zfsnap_enable_prefix-"YES"}" in
-            [Yy][Ee][Ss]) OPTIONS="$OPTIONS -p ${xPERIODICx_zfsnap_prefix:-"xPERIODICx-"}" ;;
+            [Yy][Ee][Ss]) CREATE_OPTIONS="$CREATE_OPTIONS -p ${xPERIODICx_zfsnap_prefix:-"xPERIODICx-"}" ;;
         esac
 
         case 'xPERIODICx' in
@@ -49,7 +55,9 @@ case "${xPERIODICx_zfsnap_enable-"NO"}" in
                 ;;
         esac
 
-        xPREFIXx/zfsnap snapshot $OPTIONS -a ${xPERIODICx_zfsnap_ttl:-"$default_ttl"} $xPERIODICx_zfsnap_fs -r $xPERIODICx_zfsnap_recursive_fs
+        # Destroy before create, just in case the pool is out of space
+        xPREFIXx/zfsnap destroy $DESTROY_OPTIONS -p "hourly- daily- weekly- monthly- reboot- $xPERIODICx_zfsnap_delete_prefixes" $xPERIODICx_zfsnap_fs -r $xPERIODICx_zfsnap_recursive_fs && \
+            xPREFIXx/zfsnap snapshot $CREATE_OPTIONS -a ${xPERIODICx_zfsnap_ttl:-"$default_ttl"} $xPERIODICx_zfsnap_fs -r $xPERIODICx_zfsnap_recursive_fs
         exit $?
         ;;
 
