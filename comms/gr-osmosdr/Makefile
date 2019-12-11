# $FreeBSD$

PORTNAME=	gr-osmosdr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4-127
DISTVERSIONSUFFIX=	-g4d83c60
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	comms hamradio

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GNU Radio OsmoSDR module

LICENSE=	GPLv3

BUILD_DEPENDS=	swig3.0:devel/swig30 \
		cheetah:devel/py-cheetah
LIB_DEPENDS=	libgnuradio-runtime.so:comms/gnuradio \
		libgnuradio-pmt.so:comms/gnuradio \
		libgnuradio-blocks.so:comms/gnuradio \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		liblog4cpp.so:devel/log4cpp \
		libgmpxx.so:math/gmp \
		libgmp.so:math/gmp \
		liborc-0.4.so:devel/orc

USES=	cmake compiler:c++11-lang fortran pkgconfig python:2.7 tar:tgz

USE_GITHUB=	yes
GH_ACCOUNT=	osmocom

USE_LDCONFIG=	yes
BINARY_ALIAS=	swig=swig3.0

# See lib/CMakeLists.txt to enable more components
CMAKE_ARGS+=	-DENABLE_DEFAULT:BOOL=OFF \
		-DENABLE_FILE:BOOL=ON \
		-DENABLE_PYTHON=ON \
		-DPYTHON_EXECUTABLE:STRING="${PYTHON_CMD}"

CXXFLAGS+=	-std=c++11

OPTIONS_DEFINE=	RTLSDR HACKRF
RTLSDR_DESC=	Enable rtl-sdr (RTL2832) support
OPTIONS_DEFAULT=	RTLSDR
RTLSDR_LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr
RTLSDR_CMAKE_ON=	-DENABLE_RTL:BOOL=ON -DENABLE_RTL_TCP:BOOL=ON
HACKRF_DESC=	Enable hackrf one hardware support
HACKRF_LIB_DEPENDS=	libhackrf.so:comms/hackrf
HACKRF_CMAKE_ON=	-DENABLE_HACKRF:BOOL=ON

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnuradio-osmosdr.so.0.1.5git

.include <bsd.port.mk>
