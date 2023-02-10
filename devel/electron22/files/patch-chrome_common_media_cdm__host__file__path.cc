--- chrome/common/media/cdm_host_file_path.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/common/media/cdm_host_file_path.cc
@@ -91,7 +91,7 @@ void AddCdmHostFilePaths(
   cdm_host_file_paths->emplace_back(chrome_framework_path,
                                     chrome_framework_sig_path);
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   base::FilePath chrome_exe_dir;
   if (!base::PathService::Get(base::DIR_EXE, &chrome_exe_dir))
