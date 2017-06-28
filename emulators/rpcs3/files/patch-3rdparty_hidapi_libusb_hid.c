3rdparty/hidapi/libusb/hid.c:458:18: warning: passing 'const char **' to parameter of type 'char **' discards qualifiers in nested pointer types [-Wincompatible-pointer-types-discards-qualifiers]
        res = iconv(ic, &inptr, &inbytes, &outptr, &outbytes);
                        ^~~~~~
/usr/local/include/iconv.h:85:43: note: passing argument to parameter 'inbuf' here
extern size_t iconv (iconv_t cd,  char* * inbuf, size_t *inbytesleft, char* * outbuf, size_t *outbytesleft);
                                          ^
1 warning generated.

--- 3rdparty/hidapi/libusb/hid.c.orig	2017-04-29 01:03:27 UTC
+++ 3rdparty/hidapi/libusb/hid.c
@@ -397,7 +397,7 @@ static wchar_t *get_usb_string(libusb_device_handle *d
 	size_t inbytes;
 	size_t outbytes;
 	size_t res;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && __FreeBSD__ < 10
 	const char *inptr;
 #else
 	char *inptr;
