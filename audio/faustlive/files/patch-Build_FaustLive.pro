-- add C++17 required by Qt6

--- Build/FaustLive.pro.orig	2026-07-31 18:50:05 UTC
+++ Build/FaustLive.pro
@@ -37,6 +37,8 @@ CONFIG += exceptions rtti # c++11
 
 CONFIG += exceptions rtti # c++11
 
+CONFIG += c++17
+
 ## QT libraries needed
 QT += core gui widgets network
 DEFINES += VERSION=\\\"$$VERSION\\\"
