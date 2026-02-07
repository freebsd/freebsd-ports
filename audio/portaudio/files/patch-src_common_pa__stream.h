--- src/common/pa_stream.h.orig	2018-07-17 06:44:39 UTC
+++ src/common/pa_stream.h
@@ -152,6 +152,7 @@ typedef struct PaUtilStreamRepresentation {
     PaStreamFinishedCallback *streamFinishedCallback;
     void *userData;
     PaStreamInfo streamInfo;
+    PaHostApiTypeId hostApiType;
 } PaUtilStreamRepresentation;
 
 
