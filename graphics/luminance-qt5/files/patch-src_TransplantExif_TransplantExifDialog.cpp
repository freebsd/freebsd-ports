--- src/TransplantExif/TransplantExifDialog.cpp.orig	2021-01-11 09:41:28 UTC
+++ src/TransplantExif/TransplantExifDialog.cpp
@@ -347,7 +347,7 @@ void TransplantExifDialog::transplant_requested() {
                 QFile::encodeName((*i_dest)).constData(),
                 m_Ui->checkBox_dont_overwrite->isChecked());
             m_Ui->rightlist->item(index)->setBackground(QBrush("#a0ff87"));
-        } catch (Exiv2::AnyError &e) {
+        } catch (Exiv2::Error &e) {
             add_log_message("ERROR:" + QString::fromStdString(e.what()));
             m_Ui->rightlist->item(index)->setBackground(QBrush("#ff743d"));
         }
