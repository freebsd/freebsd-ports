--- src/electronics/port.cpp.orig	2019-11-27 15:37:02 UTC
+++ src/electronics/port.cpp
@@ -22,7 +22,7 @@
 #include <sys/ioctl.h>
 #include <unistd.h>
 
-#ifndef DARWIN
+#if !defined(DARWIN) && !defined(__FreeBSD__)
 #include <linux/ppdev.h>
 #endif
 
@@ -39,7 +39,7 @@ Port::~Port()
 
 QStringList Port::ports( unsigned probeResult )
 {
-#ifndef DARWIN
+#if !defined(DARWIN) && !defined(__FreeBSD__)
 	return SerialPort::ports(probeResult) + ParallelPort::ports(probeResult);
 #else
 	return SerialPort::ports(probeResult);
@@ -264,7 +264,7 @@ const int INPUT_MODE_BIT = 1 << 21; // Controls if the
 
 // No code using these values will be reached on Darwin, this is just to
 // keep the preprocessor happy.
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 	#define PPRDATA		0xFACADE
 	#define PPRCONTROL	0xC001D00D
 	#define PPWDATA		0xC0EDBABE
@@ -379,7 +379,7 @@ void ParallelPort::setControlState( uchar pins, bool s
 //BEGIN Register-oriented operations
 uchar ParallelPort::readFromRegister( Register reg )
 {
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 	return 0;
 #endif
 	
@@ -398,7 +398,7 @@ uchar ParallelPort::readFromRegister( Register reg )
 
 void ParallelPort::writeToRegister( Register reg, uchar value )
 {
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 	return;
 #endif
 	
@@ -469,7 +469,7 @@ void ParallelPort::setControlDirection( int pins, Dire
 
 Port::ProbeResult ParallelPort::probe( const QString & port )
 {
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 	return Port::DoesntExist;
 #endif
 	
@@ -493,7 +493,7 @@ QStringList ParallelPort::ports( unsigned probeResult 
 {
 	QStringList list;
 	
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 	return list;
 #endif
 	
@@ -517,7 +517,10 @@ QStringList ParallelPort::ports( unsigned probeResult 
 
 bool ParallelPort::openPort( const QString & port )
 {
-#ifdef DARWIN
+#if defined(__FreeBSD__)
+	qWarning() << Q_FUNC_INFO << "Parallel ports disabled on FreeBSD" << endl;
+	return false;
+#elif defined(DARWIN)
 	qWarning() << Q_FUNC_INFO << "Parallel ports disabled on Darwin" << endl;
 	return false;
 #endif
@@ -550,7 +553,7 @@ bool ParallelPort::openPort( const QString & port )
 
 void ParallelPort::closePort()
 {
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 	return;
 #endif
 	
