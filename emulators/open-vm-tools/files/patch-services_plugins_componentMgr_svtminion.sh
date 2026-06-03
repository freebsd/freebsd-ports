--- services/plugins/componentMgr/svtminion.sh.orig	2025-06-19 04:05:18 UTC
+++ services/plugins/componentMgr/svtminion.sh
@@ -120,7 +120,7 @@ list_of_onedir_locations_check[0]="${onedir_pre_3006_l
 list_of_onedir_locations_check[1]="${onedir_post_3005_location}"
 
 ## VMware file and directory locations
-readonly vmtools_base_dir_etc="/etc/vmware-tools"
+readonly vmtools_base_dir_etc="%%PREFIX%%/etc/vmware-tools"
 readonly vmtools_conf_file="tools.conf"
 readonly vmtools_salt_minion_section_name="salt_minion"
 
