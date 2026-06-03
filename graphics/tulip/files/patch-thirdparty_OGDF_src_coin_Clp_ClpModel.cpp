--- thirdparty/OGDF/src/coin/Clp/ClpModel.cpp.orig	2025-03-31 21:30:23 UTC
+++ thirdparty/OGDF/src/coin/Clp/ClpModel.cpp
@@ -3619,7 +3619,7 @@ ClpModel::writeMps(const char *filename,
      writer.setMpsData(*(matrix_->getPackedMatrix()), COIN_DBL_MAX,
                        getColLower(), getColUpper(),
                        objective,
-                       reinterpret_cast<const char*> (NULL) /*integrality*/,
+                       static_cast<const char*> (NULL) /*integrality*/,
                        getRowLower(), getRowUpper(),
                        columnNames, rowNames);
      // Pass in array saying if each variable integer
