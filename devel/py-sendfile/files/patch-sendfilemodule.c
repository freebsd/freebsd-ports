--- sendfilemodule.c.orig	Sun Feb  6 13:17:43 2005
+++ sendfilemodule.c	Sun Feb  6 23:41:08 2005
@@ -174,40 +174,40 @@
 
 static PyMethodDef SendfileMethods[] = {
     {"sendfile",  method_sendfile, METH_VARARGS,
-"sendfile(out_fd, in_fd, offset, count) = [position, sent]
-
-FreeBSD only:
-sendfile(out_fd, in_fd, offset, count, headers_and_or_trailers) = [position, sent]
-
-Direct interface to FreeBSD and Linux sendfile(2) using the Linux API, except that errors are turned into Python exceptions, and instead of returning only the amount of data being sent, it returns a tuple that contains the new file pointer, and the amount of data that has been sent. 
-
-For example:
-
-from sendfile import *
-sendfile(out_socket.fileno(), in_file.fileno(), int_start, int_len)
-
-On Linux, item 0 of the return value is always a reliable file pointer. The value specified in the offset argument is handed to the syscall, which then updates it according to how much data has been sent. The length of data sent is returned in item 1 of the return value.
-
-FreeBSD sf_hdtr is also supported as an additional argument which can be a string, list, or tuple. If it is a string, it will create a struct iovec of length 1 containing the string which will be sent as the header. If a list, it will create a struct iovec of the length of the list, containing the strings in the list, which will be concatenated by the syscall to form the total header. If a tuple, it will expect a string or list of strings in two items: the first representing the header, and the second representing the trailer, processed the same way as the header. You can send only a footer by making the header an empty string or list, or list of empty strings.
-
-FreeBSD example with string header:
-
-from sendfile import *
-sendfile(out_socket.fileno(), in_file.fileno(), 0, 0, \"HTTP/1.1 200 OK\\r\\nContent-Type: text/html\\r\\nConnection: close\\r\\n\\r\\n\")
-
-FreeBSD example with both header and trailer as a string:
-
-from sendfile import *
-sendfile(out_socket.fileno(), in_file.fileno(), int_start, int_len, ('BEGIN', 'END'))
-
-FreeBSD example with mixed types:
-
-from sendfile import *
-sendfile(out_socket.fileno(), in_file.fileno(), int_start, int_len, ([magic, metadata_len, metadata, data_len], md5))
-
-Although the FreeBSD sendfile(2) requires the socket file descriptor to be specified as the second argument, this function will ALWAYS require the socket as the first argument, like Linux and Solaris. Also, if an sf_hdtr is specified, the function will return the total data sent including all of the headers and trailers. Note that item 0 of the return value, the file pointer position, is determined on FreeBSD only by adding offset and count, so if not all of the data has been sent, this value will be wrong. You will have to use the value in item 1, which tells you how much total data has actually been sent, and be aware that header and trailer data are included in that value, so you may need to reconstruct the headers and/or trailers yourself if you would like to find out exactly which data has been sent. However, if you do not send any headers or trailers, you can just add item 1 to where you started to find out where you need to start from again. I do not consider this much of a problem because if you are sending header and trailer data, the protocol will likely not allow you to just keep sending from where the failure occured without getting into complexities, anyway. 
-
-The variable has_sf_hdtr is provided for determining whether sf_hdtr is supported."},
+"sendfile(out_fd, in_fd, offset, count) = [position, sent]"
+""
+"FreeBSD only:"
+"sendfile(out_fd, in_fd, offset, count, headers_and_or_trailers) = [position, sent]"
+""
+"Direct interface to FreeBSD and Linux sendfile(2) using the Linux API, except that errors are turned into Python exceptions, and instead of returning only the amount of data being sent, it returns a tuple that contains the new file pointer, and the amount of data that has been sent. "
+""
+"For example:"
+""
+"from sendfile import *"
+"sendfile(out_socket.fileno(), in_file.fileno(), int_start, int_len)"
+""
+"On Linux, item 0 of the return value is always a reliable file pointer. The value specified in the offset argument is handed to the syscall, which then updates it according to how much data has been sent. The length of data sent is returned in item 1 of the return value."
+""
+"FreeBSD sf_hdtr is also supported as an additional argument which can be a string, list, or tuple. If it is a string, it will create a struct iovec of length 1 containing the string which will be sent as the header. If a list, it will create a struct iovec of the length of the list, containing the strings in the list, which will be concatenated by the syscall to form the total header. If a tuple, it will expect a string or list of strings in two items: the first representing the header, and the second representing the trailer, processed the same way as the header. You can send only a footer by making the header an empty string or list, or list of empty strings."
+""
+"FreeBSD example with string header:"
+""
+"from sendfile import *"
+"sendfile(out_socket.fileno(), in_file.fileno(), 0, 0, \"HTTP/1.1 200 OK\\r\\nContent-Type: text/html\\r\\nConnection: close\\r\\n\\r\\n\")"
+""
+"FreeBSD example with both header and trailer as a string:"
+""
+"from sendfile import *"
+"sendfile(out_socket.fileno(), in_file.fileno(), int_start, int_len, ('BEGIN', 'END'))"
+""
+"FreeBSD example with mixed types:"
+""
+"from sendfile import *"
+"sendfile(out_socket.fileno(), in_file.fileno(), int_start, int_len, ([magic, metadata_len, metadata, data_len], md5))"
+""
+"Although the FreeBSD sendfile(2) requires the socket file descriptor to be specified as the second argument, this function will ALWAYS require the socket as the first argument, like Linux and Solaris. Also, if an sf_hdtr is specified, the function will return the total data sent including all of the headers and trailers. Note that item 0 of the return value, the file pointer position, is determined on FreeBSD only by adding offset and count, so if not all of the data has been sent, this value will be wrong. You will have to use the value in item 1, which tells you how much total data has actually been sent, and be aware that header and trailer data are included in that value, so you may need to reconstruct the headers and/or trailers yourself if you would like to find out exactly which data has been sent. However, if you do not send any headers or trailers, you can just add item 1 to where you started to find out where you need to start from again. I do not consider this much of a problem because if you are sending header and trailer data, the protocol will likely not allow you to just keep sending from where the failure occured without getting into complexities, anyway. "
+""
+"The variable has_sf_hdtr is provided for determining whether sf_hdtr is supported."},
     {NULL, NULL, 0, NULL}        /* Sentinel */
 };
 
