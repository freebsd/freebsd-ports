--- include/MySQL_HostGroups_Manager.h.orig	2025-11-05 18:26:00 UTC
+++ include/MySQL_HostGroups_Manager.h
@@ -1250,9 +1250,9 @@ T j_get_srv_default_int_val(
 				return val;
 			} else {
 				proxy_error(
-					"Invalid value %ld supplied for 'mysql_hostgroup_attributes.servers_defaults.%s' for hostgroup %d."
+					"Invalid value %lld supplied for 'mysql_hostgroup_attributes.servers_defaults.%s' for hostgroup %d."
 						" Value NOT UPDATED.\n",
-					static_cast<int64_t>(val), key.c_str(), hid
+					static_cast<long long int>(val), key.c_str(), hid
 				);
 			}
 		} else {
