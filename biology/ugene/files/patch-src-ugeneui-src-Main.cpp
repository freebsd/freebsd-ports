--- src/ugeneui/src/Main.cpp.orig
+++ src/ugeneui/src/Main.cpp
@@ -164,7 +164,7 @@ static void setDataSearchPaths() {
         dataSearchPaths.push_back( appDirPath+RELATIVE_DEV_DATA_DIR );
     }
 
-#if (defined(Q_OS_LINUX) || defined(Q_OS_UNIX)) && defined( UGENE_DATA_DIR )
+#if defined(Q_OS_UNIX) && defined(UGENE_DATA_DIR)
     //using directory which is set during installation process on Linux
     QString ugene_data_dir( UGENE_DATA_DIR );
     if( QDir(ugene_data_dir).exists() ) {
@@ -361,7 +361,7 @@ int main(int argc, char **argv) 
     qt_use_native_dialogs = useNative; //using local here for debugger
 #endif
 
-#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
+#if defined(Q_OS_UNIX)
     if (envList.indexOf("UGENE_GUI_TEST=1") >= 0) {
         QApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
     }
