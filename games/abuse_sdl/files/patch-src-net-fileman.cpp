fileman.cpp:296:33: error: non-constant-expression cannot be narrowed from type 'unsigned long' to 'uint8_t' (aka 'unsigned char') in initializer list [-Wc++11-narrowing]
  uint8_t sizes[3]={ CLIENT_NFS,strlen(filename)+1,strlen(mode)+1};
                                ^~~~~~~~~~~~~~~~~~
fileman.cpp:296:33: note: insert an explicit cast to silence this issue
  uint8_t sizes[3]={ CLIENT_NFS,strlen(filename)+1,strlen(mode)+1};
                                ^~~~~~~~~~~~~~~~~~
                                static_cast<uint8_t>( )
fileman.cpp:296:52: error: non-constant-expression cannot be narrowed from type 'unsigned long' to 'uint8_t' (aka 'unsigned char') in initializer list [-Wc++11-narrowing]
  uint8_t sizes[3]={ CLIENT_NFS,strlen(filename)+1,strlen(mode)+1};
                                                   ^~~~~~~~~~~~~~
fileman.cpp:296:52: note: insert an explicit cast to silence this issue
  uint8_t sizes[3]={ CLIENT_NFS,strlen(filename)+1,strlen(mode)+1};
                                                   ^~~~~~~~~~~~~~
                                                   static_cast<uint8_t>( )

--- src/net/fileman.cpp.orig	2011-05-02 11:55:06 UTC
+++ src/net/fileman.cpp
@@ -293,7 +293,7 @@ file_manager::remote_file::remote_file(net_socket *soc
   next=Next;
   open_local=0;
 
-  uint8_t sizes[3]={ CLIENT_NFS,strlen(filename)+1,strlen(mode)+1};
+  uint8_t sizes[3]={ CLIENT_NFS,(uint8_t)(strlen(filename)+1),(uint8_t)(strlen(mode)+1)};
   if (sock->write(sizes,3)!=3) { r_close("could not send open info"); return ; }
   if (sock->write(filename,sizes[1])!=sizes[1]) { r_close("could not send filename"); return ; }
   if (sock->write(mode,sizes[2])!=sizes[2]) { r_close("could not send mode"); return ; }
