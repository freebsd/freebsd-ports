--- kaptain/communication.h.orig	Sat Mar  2 19:56:32 2002
+++ kaptain/communication.h	Fri Dec 20 16:14:31 2002
@@ -12,7 +12,7 @@
   QSocketNotifier * reader;
   bool ok;
   bool input, output;
-  string message; // buffer
+  std::string message; // buffer
 
 public:
   Communicator();
@@ -21,19 +21,19 @@
   bool is_stdin();
 
   bool setup_stdio();
-  bool setup_progio(string);
-  bool setup_socket_server(string);
-  bool setup_socket_client(string);
+  bool setup_progio(std::string);
+  bool setup_socket_server(std::string);
+  bool setup_socket_client(std::string);
 
   bool setup_stdin();
   bool setup_stdout();
-  bool setup_filein(string);
-  bool setup_fileout(string);
+  bool setup_filein(std::string);
+  bool setup_fileout(std::string);
 
   void no_input() {input=false;}
   void no_output() {output=false;}
 
-  void send(string);
+  void send(std::string);
 
 public slots:
   void data_arrived(int);
