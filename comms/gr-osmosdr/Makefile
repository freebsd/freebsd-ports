# $FreeBSD$

PORTNAME=	gr-osmosdr
PORTVERSION=	20130509
PORTREVISION=	6
CATEGORIES=	comms hamradio
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GNU Radio OsmoSDR module

LICENSE=	GPLv3

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
		cheetah:${PORTSDIR}/devel/py-cheetah
LIB_DEPENDS=	libgnuradio-core.so:${PORTSDIR}/comms/gnuradio \
		libgnuradio-fcd.so:${PORTSDIR}/comms/gnuradio \
		libgruel.so:${PORTSDIR}/comms/gnuradio \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs

USES=	pkgconfig cmake
USE_LDCONFIG=	yes
USE_PYTHON=	yes

CMAKE_ARGS+=	-DENABLE_DEFAULT:BOOL=OFF \
		-DENABLE_FCD:BOOL=ON \
		-DENABLE_FILE:BOOL=ON

OPTIONS_DEFINE=	RTLSDR
RTLSDR_DESC=	Enable rtl-sdr (RTL2832) support
OPTIONS_DEFAULT=	RTLSDR
RTLSDR_LIB_DEPENDS=	librtlsdr.so:${PORTSDIR}/comms/rtl-sdr
RTLSDR_CMAKE_ON=	-DENABLE_RTL:BOOL=ON -DENABLE_RTL_TCP:BOOL=ON

post-install:
	@${LN} -sf libgnuradio-osmosdr.so.0.0.1git \
		${STAGEDIR}${PREFIX}/lib/libgnuradio-osmosdr.so.0

.include <bsd.port.mk>
