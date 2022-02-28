--- filesel/cdfs/iso9660.c.orig	2022-02-28 13:33:37 UTC
+++ filesel/cdfs/iso9660.c
@@ -1140,8 +1140,7 @@ static void CDFS_Render_RockRidge_directory (struct cd
 		}
 
 		if ((directory->dirents_data[i]->Flags & ISO9660_DIRENT_FLAGS_DIR) || directory->dirents_data[i]->RockRidge_IsAugmentedDirectory)
-		{
-dir:
+		{dir:;{ /* clang is stricter than gcc, no labels before variables */
 			uint32_t Location = directory->dirents_data[i]->Absolute_Location;
 			uint32_t this_directory_handle = CDFS_Directory_add (disc, parent_directory, temp);
 			if (directory->dirents_data[i]->RockRidge_IsAugmentedDirectory)
@@ -1156,8 +1155,7 @@ dir:
 					break;
 				}
 			}
-		} else {
-file:
+		}} else {file:;{ /* clang is stricter than gcc, no labels before variables */
 			int handle = CDFS_File_add (disc, parent_directory, temp);
 			struct iso_dirent_t *iter;
 			uint32_t Length = directory->dirents_data[i]->Length;
@@ -1170,7 +1168,7 @@ file:
 				}
 				CDFS_File_extent (disc, handle, iter->Absolute_Location, RunLength, 0);
 			}
-		}
+		}}
 next:
 		free (temp);
 	}
