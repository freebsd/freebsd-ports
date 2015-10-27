# $FreeBSD$

PORTNAME=	gr-osmosdr
PORTVERSION=	20150716
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GNU Radio OsmoSDR module

LICENSE=	GPLv3

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
		cheetah:${PORTSDIR}/devel/py-cheetah
LIB_DEPENDS=	libgnuradio-runtime.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-pmt.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-blocks.so:${PORTSDIR}/comms/gnuradio \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs

USES=	cmake pkgconfig python tar:tgz
USE_LDCONFIG=	yes

# See lib/CMakeLists.txt to enable more components
CMAKE_ARGS+=	-DENABLE_DEFAULT:BOOL=OFF \
		-DENABLE_FCD:BOOL=ON \
		-DENABLE_FILE:BOOL=ON \
		-DENABLE_PYTHON=ON

OPTIONS_DEFINE=	RTLSDR
RTLSDR_DESC=	Enable rtl-sdr (RTL2832) support
OPTIONS_DEFAULT=	RTLSDR
RTLSDR_LIB_DEPENDS=	librtlsdr.so:${PORTSDIR}/comms/rtl-sdr
RTLSDR_CMAKE_ON=	-DENABLE_RTL:BOOL=ON -DENABLE_RTL_TCP:BOOL=ON

.include <bsd.port.mk>
