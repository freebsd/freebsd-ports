
$FreeBSD$

--- source/basestrm.h	2002/10/18 12:10:03	1.1
+++ source/basestrm.h	2002/10/18 12:10:30
@@ -516,7 +516,7 @@
 
 
 
-class tanycompression : public t_compressor_stream_interface, protected tlzwstreamcompression {
+class tanycompression : public t_compressor_stream_interface, public tlzwstreamcompression {
 
                             typedef deque<char> CDQ;
                             queue<char, CDQ> _queue;
