# $FreeBSD$

PORTNAME=	gr-osmosdr
PORTVERSION=	20130509
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GNU Radio OsmoSDR module

LICENSE=	GPLv3

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
		cheetah:${PORTSDIR}/devel/py-cheetah
LIB_DEPENDS=	gnuradio-core:${PORTSDIR}/comms/gnuradio \
		gnuradio-fcd:${PORTSDIR}/comms/gnuradio \
		gruel:${PORTSDIR}/comms/gnuradio \
		boost_system:${PORTSDIR}/devel/boost-libs \
		boost_thread:${PORTSDIR}/devel/boost-libs

USES=	pkgconfig cmake
USE_LDCONFIG=	yes
USE_PYTHON=	2.7+

CMAKE_ARGS+=	-DENABLE_DEFAULT:BOOL=OFF \
		-DENABLE_FCD:BOOL=ON \
		-DENABLE_FILE:BOOL=ON

OPTIONS_DEFINE=	RTLSDR
RTLSDR_DESC=	Enable rtl-sdr (RTL2832) support
OPTIONS_DEFAULT=	RTLSDR

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRTLSDR}
LIB_DEPENDS+=	rtlsdr:${PORTSDIR}/comms/rtl-sdr
CMAKE_ARGS+=	-DENABLE_RTL:BOOL=ON \
		-DENABLE_RTL_TCP:BOOL=ON
.endif

post-install:
	${LN} -s libgnuradio-osmosdr.so.0.0.1git ${PREFIX}/lib/libgnuradio-osmosdr.so.0

.include <bsd.port.mk>
