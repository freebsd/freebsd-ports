--- lib/Protein_pdb.cc.orig	2019-02-05 18:17:52 UTC
+++ lib/Protein_pdb.cc
@@ -23,6 +23,7 @@ MA 02111-1307, USA. */
 #include "pdb_utils.h"
 #include <dsrpdb_internal/Error_logger.h>
 #include <sstream>
+#include <string.h>
 
 namespace dsrpdb {
 
