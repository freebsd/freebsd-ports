--- src/gui/src/SoundLibrary/SoundLibraryExportDialog.cpp.orig	2020-08-03 19:45:59 UTC
+++ src/gui/src/SoundLibrary/SoundLibraryExportDialog.cpp
@@ -90,6 +90,7 @@ void SoundLibraryExportDialog::on_exportBtn_clicked()
 	Drumkit*	pDrumkit = nullptr;
 	
 	QDir qdTempFolder( Filesystem::tmp_dir() );
+	bool TmpFileCreated = false;
 
 	int componentID = -1;
 	
@@ -100,6 +101,8 @@ void SoundLibraryExportDialog::on_exportBtn_clicked()
 				QString temporaryDrumkitXML = qdTempFolder.filePath( "drumkit.xml" );
 				INFOLOG( "[ExportSoundLibrary]" );
 				INFOLOG( "Saving temporary file into: " + temporaryDrumkitXML );
+				
+				TmpFileCreated = true;
 				
 				for (std::vector<DrumkitComponent*>::iterator it = pDrumkit->get_components()->begin() ; it != pDrumkit->get_components()->end(); ++it) {
 					DrumkitComponent* pComponent = *it;
