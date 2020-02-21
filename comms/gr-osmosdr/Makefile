# $FreeBSD$

PORTNAME=	gr-osmosdr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTEPOCH=	1
CATEGORIES=	comms hamradio

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GNU Radio OsmoSDR module

LICENSE=	GPLv3

LIB_DEPENDS=	libgnuradio-runtime.so:comms/gnuradio \
		libgnuradio-pmt.so:comms/gnuradio \
		libgnuradio-blocks.so:comms/gnuradio \
		libvolk.so:comms/gnuradio \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		liblog4cpp.so:devel/log4cpp \
		libgmpxx.so:math/gmp \
		libgmp.so:math/gmp \
		liborc-0.4.so:devel/orc

USES=	cmake compiler:c++11-lang fortran pkgconfig tar:tgz

SUB_LIST=	VERSION=${PORTVERSION}
SUB_FILES=	gnuradio-osmosdr.pc

USE_GITHUB=	yes
GH_ACCOUNT=	osmocom

USE_LDCONFIG=	yes

# See lib/CMakeLists.txt to enable more components
# XXX Python support disabled because gr-osmosdr now requires Python 3
# while Gnuradio still uses Python 2. As a consequence, GR_PYTHON_DIR forcibly
# points to Python 2 directory (which is incorrect to install version 3 code).
# We will re-enable Python support once Gnuradio switches to Python 3
CMAKE_ARGS+=	-DENABLE_FILE:BOOL=ON \
		-DENABLE_PYTHON=OFF

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnuradio-osmosdr.so.0.2.0
	${INSTALL_DATA} ${WRKDIR}/gnuradio-osmosdr.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
