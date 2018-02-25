--- lib/wiper/wiperPosix.c.orig	2018-02-24 17:51:48 UTC
+++ lib/wiper/wiperPosix.c
@@ -143,6 +143,7 @@ static const PartitionInfo gKnownPartitions[] = {
    { "ntfs",      PARTITION_NTFS,         NULL,                   TRUE        },
    { "pcfs",      PARTITION_PCFS,         NULL,                   TRUE        },
    { "reiserfs",  PARTITION_REISERFS,     NULL,                   TRUE        },
+   { "ufs",       PARTITION_UFS,          NULL,                   TRUE        },
    { "vfat",      PARTITION_FAT,          NULL,                   TRUE        },
    { "zfs",       PARTITION_ZFS,          NULL,                   FALSE       },
    { "xfs",       PARTITION_XFS,          NULL,                   TRUE        },
