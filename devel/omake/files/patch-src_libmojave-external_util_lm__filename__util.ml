$NetBSD: patch-au,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/util/lm_filename_util.ml.orig	2007-01-29 20:14:42.000000000 +0000
+++ src/libmojave-external/util/lm_filename_util.ml
@@ -48,12 +48,11 @@ let groups =
 let unix_is_executable s =
    let flag =
       try
-         let { Unix.LargeFile.st_kind = kind;
-               Unix.LargeFile.st_perm = perm;
-               Unix.LargeFile.st_uid = uid;
-               Unix.LargeFile.st_gid = gid
-             } = Unix.LargeFile.stat s
-         in
+         let st = Unix.LargeFile.stat s in
+         let kind = st.Unix.LargeFile.st_kind in
+         let perm = st.Unix.LargeFile.st_perm in
+         let uid = st.Unix.LargeFile.st_uid in
+         let gid = st.Unix.LargeFile.st_gid in
             (kind = Unix.S_REG)
             && ((perm land 0o001) <> 0
                 || (List.mem gid groups && (perm land 0o010) <> 0)
