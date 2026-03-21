--- src/OrcaSlicer.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/OrcaSlicer.cpp
@@ -23,7 +23,7 @@
 #include <iostream>
 #include <math.h>
 
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
 #include <condition_variable>
 #include <mutex>
 #include <boost/thread.hpp>
@@ -166,7 +166,7 @@ std::vector<PrintBase::SlicingStatus> g_slicing_warnin
 }sliced_info_t;
 std::vector<PrintBase::SlicingStatus> g_slicing_warnings;
 
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
 #define PIPE_BUFFER_SIZE 512
 
 typedef struct _cli_callback_mgr {
@@ -379,7 +379,7 @@ static PrinterTechnology get_printer_technology(const 
 }
 
 //BBS: add flush and exit
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
 #define flush_and_exit(ret)     { boost::nowide::cout << __FUNCTION__ << " found error, return "<<ret<<", exit..." << std::endl;\
     g_cli_callback_mgr.stop();\
     boost::nowide::cout.flush();\
@@ -400,7 +400,7 @@ void record_exit_reson(std::string outputdir, int code
 
 void record_exit_reson(std::string outputdir, int code, int plate_id, std::string error_message, sliced_info_t& sliced_info, std::map<std::string, std::string> key_values = std::map<std::string, std::string>())
 {
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
     std::string result_file;
 
     if (!outputdir.empty())
@@ -1262,7 +1262,7 @@ int CLI::run(int argc, char **argv)
         pipe_name = pipe_option->value;
         if (!pipe_name.empty()) {
             BOOST_LOG_TRIVIAL(info) << boost::format("Will use pipe %1%")%pipe_name;
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
             g_cli_callback_mgr.start(pipe_name);
             PrintBase::SlicingStatus slicing_status{1, "Start to load files"};
             cli_status_callback(slicing_status);
@@ -3396,7 +3396,7 @@ int CLI::run(int argc, char **argv)
     ArrangeParams arrange_cfg;
 
     BOOST_LOG_TRIVIAL(info) << "will start transforms, commands count " << m_transforms.size() << "\n";
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
     if (g_cli_callback_mgr.is_started()) {
         PrintBase::SlicingStatus slicing_status{2, "Loading files finished"};
         cli_status_callback(slicing_status);
@@ -4735,7 +4735,7 @@ int CLI::run(int argc, char **argv)
                 flush_and_exit(1);
             }*/
             BOOST_LOG_TRIVIAL(info) << "Need to slice for plate "<<plate_to_slice <<", total plate count "<<partplate_list.get_plate_count()<<" partplates!" << std::endl;
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
             if (g_cli_callback_mgr.is_started()) {
                 PrintBase::SlicingStatus slicing_status{3, "Prepare slicing"};
                 cli_status_callback(slicing_status);
@@ -4947,7 +4947,7 @@ int CLI::run(int argc, char **argv)
                             try {
                                 std::string outfile_final;
                                 BOOST_LOG_TRIVIAL(info) << "start Print::process for partplate "<<index+1 << std::endl;
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
                                 BOOST_LOG_TRIVIAL(info) << "cli callback mgr started:  "<<g_cli_callback_mgr.m_started << std::endl;
                                 if (g_cli_callback_mgr.is_started()) {
                                     BOOST_LOG_TRIVIAL(info) << "set print's callback to cli_status_callback.";
@@ -5001,7 +5001,7 @@ int CLI::run(int argc, char **argv)
                                     }
                                     else {
                                         BOOST_LOG_TRIVIAL(info) << "plate "<< index+1<< ": load cached data success, go on.";
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
                                         if (g_cli_callback_mgr.is_started()) {
                                             PrintBase::SlicingStatus slicing_status{69, "Cache data loaded"};
                                             cli_status_callback(slicing_status);
@@ -5090,7 +5090,7 @@ int CLI::run(int argc, char **argv)
                                 //run_post_process_scripts(outfile, print->full_print_config());
                                 BOOST_LOG_TRIVIAL(info) << "Slicing result exported to " << outfile << std::endl;
                                 part_plate->update_slice_result_valid_state(true);
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
                                 if (g_cli_callback_mgr.is_started()) {
                                     PrintBase::SlicingStatus slicing_status{100, "Slicing finished"};
                                     cli_status_callback(slicing_status);
@@ -5140,7 +5140,7 @@ int CLI::run(int argc, char **argv)
                         finished = true;
                 }//end for partplate
 
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
                 if (g_cli_callback_mgr.is_started()) {
                     int plate_count = (plate_to_slice== 0)?partplate_list.get_plate_count():1;
                     g_cli_callback_mgr.set_plate_info(0, plate_count);
@@ -5218,7 +5218,7 @@ int CLI::run(int argc, char **argv)
             export_3mf_file = outfile_dir + "/"+export_3mf_file;
         }
 
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
         if (g_cli_callback_mgr.is_started()) {
             PrintBase::SlicingStatus slicing_status{94, "Generate thumbnails"};
             cli_status_callback(slicing_status);
@@ -5375,7 +5375,7 @@ int CLI::run(int argc, char **argv)
                 glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                 glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_OSMESA_CONTEXT_API);
 #endif
 
@@ -5850,7 +5850,7 @@ int CLI::run(int argc, char **argv)
         }
 
 
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
         if (g_cli_callback_mgr.is_started()) {
             PrintBase::SlicingStatus slicing_status{97, "Exporting 3mf"};
             cli_status_callback(slicing_status);
@@ -5908,7 +5908,7 @@ int CLI::run(int argc, char **argv)
         release_PlateData_list(plate_data_src);
     }
 
-#if defined(__linux__) || defined(__LINUX__)
+#if defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
     if (g_cli_callback_mgr.is_started()) {
         PrintBase::SlicingStatus slicing_status{100, "All done, Success"};
         cli_status_callback(slicing_status);
