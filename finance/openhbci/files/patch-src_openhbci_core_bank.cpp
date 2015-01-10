--- src/openhbci/core/bank.cpp.orig	2003-04-25 01:45:54 UTC
+++ src/openhbci/core/bank.cpp
@@ -39,7 +39,7 @@ instituteMessage::instituteMessage()
 instituteMessage::~instituteMessage(){
 }
 
-const bool instituteMessage::operator==(const instituteMessage &msg) {
+bool instituteMessage::operator==(const instituteMessage &msg) const {
     return (_date == msg._date &&
 			0 == _time.compare(msg._time) &&
 			_subject == msg._subject &&
