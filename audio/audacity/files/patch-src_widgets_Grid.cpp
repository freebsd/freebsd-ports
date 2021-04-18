--- src/widgets/Grid.cpp.orig	2021-02-04 18:52:51 UTC
+++ src/widgets/Grid.cpp
@@ -572,7 +572,7 @@ void Grid::OnKeyDown(wxKeyEvent &event)
          {
             wxTextDataObject *data = safenew wxTextDataObject(GetCellValue(crow, ccol));
             wxClipboard::Get()->SetData(data);
-            SetCellValue(crow, ccol, {});
+            SetCellValue(crow, ccol, "");
             return;
          }
          break;
