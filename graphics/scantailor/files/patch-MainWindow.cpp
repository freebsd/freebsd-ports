--- MainWindow.cpp.orig	2012-02-27 20:21:08 UTC
+++ MainWindow.cpp
@@ -1896,8 +1896,8 @@ MainWindow::showInsertFileDialog(BeforeO
 		ImageFileInfo image_file_info(file_info, std::vector<ImageMetadata>());
 
 		ImageMetadataLoader::Status const status = ImageMetadataLoader::load(
-			files.at(i), bind(&std::vector<ImageMetadata>::push_back,
-			boost::ref(image_file_info.imageInfo()), _1)
+			files.at(i), boost::lambda::bind(&std::vector<ImageMetadata>::push_back,
+			boost::ref(image_file_info.imageInfo()), boost::lambda::_1)
 		);
 
 		if (status == ImageMetadataLoader::LOADED) {
@@ -1919,7 +1919,7 @@ MainWindow::showInsertFileDialog(BeforeO
 	}
 
 	// Check if there is at least one DPI that's not OK.
-	if (std::find_if(new_files.begin(), new_files.end(), !bind(&ImageFileInfo::isDpiOK, _1)) != new_files.end()) {
+	if (std::find_if(new_files.begin(), new_files.end(), !boost::lambda::bind(&ImageFileInfo::isDpiOK, boost::lambda::_1)) != new_files.end()) {
 
 		std::auto_ptr<FixDpiDialog> dpi_dialog(new FixDpiDialog(new_files, this));
 		dpi_dialog->setWindowModality(Qt::WindowModal);
