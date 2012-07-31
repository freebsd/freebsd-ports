$FreeBSD$

diff --git a/libarchive/archive_read_disk_entry_from_file.c b/libarchive/archive_read_disk_entry_from_file.c
index 7987fa5..25b1edc 100644
--- a/libarchive/archive_read_disk_entry_from_file.c
+++ b/libarchive/archive_read_disk_entry_from_file.c
@@ -584,6 +584,7 @@ translate_acl(struct archive_read_disk *a,
 			break;
 		default:
 			/* Skip types that libarchive can't support. */
+			s = acl_get_entry(acl, ACL_NEXT_ENTRY, &acl_entry);
 			continue;
 		}
 
