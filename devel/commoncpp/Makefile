# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	commoncpp2
PORTVERSION=	1.0.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	commonc++	

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU project portable class framework for C++

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2


USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN3=		AtomicCounter.3cc BaseObject.3cc BroadcastAddress.3cc \
		Buffer.3cc CRC16Digest.3cc CRC32Digest.3cc \
		ChecksumDigest.3cc CommandOption.3cc CommandOptionArg.3cc \
		CommandOptionCollect.3cc CommandOptionNoArg.3cc \
		CommandOptionParse.3cc CommandOptionRest.3cc \
		CommandOptionWithArg.3cc Conditional.3cc \
		DSO.3cc Date.3cc DateNumber.3cc Datetime.3cc \
		Digest.3cc DigestException.3cc Dir.3cc Engine.3cc \
		Engine_Exception.3cc Event.3cc FIFOSession.3cc \
		FTPSocket.3cc FTPSocket_DirEntry.3cc \
		FTPSocket_DirEntry_Compare.3cc File.3cc \
		FixedBuffer.3cc InetAddrValidator.3cc \
		InetAddress.3cc InetHostAddress.3cc InetMaskAddress.3cc \
		InetMcastAddrValidator.3cc InetMcastAddress.3cc \
		Keydata.3cc Keydata_Define.3cc Keydata_Keysym.3cc \
		Keydata_Keyval.3cc MD5Digest.3cc MappedFile.3cc \
		MemPager.3cc Mutex.3cc MutexCounter.3cc MutexLock.3cc \
		NetworkDeviceInfo.3cc Number.3cc PersistException.3cc \
		Pipe.3cc PluginGroup.3cc Process.3cc RandomFile.3cc \
		SHA1Digest.3cc SHA256Digest.3cc SHA64DigestHelper.3cc \
		SHAConstant.3cc SHADigest.3cc SHATumbler.3cc Semaphore.3cc \
		Serial.3cc SerialPort.3cc SerialService.3cc SharedFile.3cc \
		SharedMemPager.3cc Slog.3cc Socket.3cc SocketPort.3cc \
		SocketService.3cc StringTokenizer.3cc \
		StringTokenizer_NoSuchElementException.3cc \
		StringTokenizer_iterator.3cc TCPSession.3cc \
		TCPSocket.3cc TCPStream.3cc TTYSession.3cc TTYStream.3cc \
		Thread.3cc ThreadFile.3cc ThreadGroup.3cc ThreadKey.3cc \
		ThreadLock.3cc Time.3cc TimedGroup.3cc TimerPort.3cc \
		TypeManager.3cc TypeManager_Registration.3cc UDPBroadcast.3cc \
		UDPDuplex.3cc UDPReceive.3cc UDPSocket.3cc UDPTransmit.3cc \
		URLStream.3cc UnixSession.3cc UnixSocket.3cc UnixStream.3cc \
		ZNumber.3cc cmdoptns.h.3cc common.h.3cc config.h.3cc \
		counter.h.3cc digest.h.3cc exception.h.3cc export.h.3cc \
		fifostream.3cc file.h.3cc ftp.h.3cc functions.h.3cc \
		groups.h.3cc iftpstream.3cc keystring.3cc misc.h.3cc \
		network.h.3cc numbers.h.3cc objcount.h.3cc objlink.h.3cc \
		objmap.h.3cc objsync.h.3cc oftpstream.3cc ost.3cc \
		ost_AtomicCounter.3cc ost_BaseObject.3cc \
		ost_BroadcastAddress.3cc ost_Buffer.3cc \
		ost_CRC16Digest.3cc ost_CRC32Digest.3cc \
		ost_ChecksumDigest.3cc ost_CommandOption.3cc \
		ost_CommandOptionArg.3cc ost_CommandOptionCollect.3cc \
		ost_CommandOptionNoArg.3cc ost_CommandOptionParse.3cc \
		ost_CommandOptionRest.3cc ost_CommandOptionWithArg.3cc \
		ost_Conditional.3cc ost_Counter.3cc ost_DSO.3cc ost_Date.3cc \
		ost_DateNumber.3cc ost_Datetime.3cc ost_Digest.3cc \
		ost_DigestException.3cc ost_Dir.3cc ost_Engine.3cc \
		ost_Engine_Exception.3cc ost_Event.3cc ost_FIFOSession.3cc \
		ost_File.3cc ost_File__fcb.3cc ost_FixedBuffer.3cc \
		ost_InetAddrValidator.3cc ost_InetAddress.3cc \
		ost_InetHostAddress.3cc ost_InetMaskAddress.3cc \
		ost_InetMcastAddrValidator.3cc ost_InetMcastAddress.3cc \
		ost_Keydata.3cc ost_Keydata_Define.3cc ost_Keydata_Keysym.3cc \
		ost_Keydata_Keyval.3cc ost_MD5Digest.3cc ost_MappedFile.3cc \
		ost_MemPager.3cc ost_Mutex.3cc ost_MutexCounter.3cc \
		ost_MutexLock.3cc ost_NetworkDeviceInfo.3cc \
		ost_Number.3cc ost_PersistException.3cc ost_Pipe.3cc \
		ost_PluginGroup.3cc ost_Pointer.3cc ost_Poller.3cc \
		ost_PosixThread.3cc ost_Process.3cc ost_RandomFile.3cc \
		ost_SHA1Digest.3cc ost_SHA256Digest.3cc \
		ost_SHA64DigestHelper.3cc ost_SHAConstant.3cc \
		ost_SHADigest.3cc ost_SHATumbler.3cc ost_Semaphore.3cc \
		ost_Serial.3cc ost_SerialPort.3cc ost_SerialService.3cc \
		ost_SharedFile.3cc ost_SharedMemPager.3cc ost_Slog.3cc \
		ost_Socket.3cc ost_SocketPort.3cc ost_SocketService.3cc \
		ost_StringTokenizer.3cc \
		ost_StringTokenizer_NoSuchElementException.3cc \
		ost_StringTokenizer_iterator.3cc ost_TCPSession.3cc \
		ost_TCPSocket.3cc ost_TCPStream.3cc ost_TTYSession.3cc \
		ost_TTYStream.3cc ost_Thread.3cc ost_ThreadFile.3cc \
		ost_ThreadGroup.3cc \
		ost_ThreadKey.3cc ost_ThreadLock.3cc ost_Time.3cc \
		ost_TimedGroup.3cc ost_TimerPort.3cc ost_TypeManager.3cc \
		ost_TypeManager_Registration.3cc ost_UDPBroadcast.3cc \
		ost_UDPDuplex.3cc ost_UDPReceive.3cc ost_UDPSocket.3cc \
		ost_UDPTransmit.3cc ost_URLStream.3cc ost_UnixSession.3cc \
		ost_UnixSocket.3cc ost_UnixStream.3cc ost_XMLRPC.3cc \
		ost_XMLStream.3cc ost_ZNumber.3cc \
		ost_cistring_char_traits.3cc ost_fifostream.3cc \
		ost_keyMap.3cc ost_keystring.3cc ost_objCounter.3cc \
		ost_objList.3cc ost_objMap.3cc ost_objSync.3cc \
		ost_tcpstream.3cc ost_ttystream.3cc ost_unixstream.3cc \
		oststring.h.3cc persist.h.3cc pointer.h.3cc process.h.3cc \
		serial.h.3cc slog.h.3cc socket.h.3cc strchar.h.3cc \
		tcpstream.3cc template.h.3cc thread.h.3cc ttystream.3cc \
		unix.h.3cc unixstream.3cc url.h.3cc urlstring.h.3cc \
		xml.h.3cc

post-install:
	(cd ${WRKSRC} ; make man)

.include <bsd.port.mk>
