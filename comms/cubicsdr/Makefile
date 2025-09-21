PORTNAME=	cubicsdr
PORTVERSION=	0.2.7
PORTREVISION=	4
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	SDR receiver using liquidsdr
WWW=		https://cubicsdr.readthedocs.io/en/latest/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhamlib.so:comms/hamlib \
		libliquid.so:comms/liquid-dsp \
		libpulse.so:audio/pulseaudio \
		libSoapySDR.so:misc/soapysdr
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri \
		${PYNUMPY}

USES=		cmake:noninja compiler:c++11-lib gl python
USE_GL+=	egl glu
USE_WX=		3.2

OPTIONS_DEFINE=		HAMLIB
OPTIONS_DEFAULT=	HAMLIB
HAMLIB_DESC=		Support rig control via hamlib
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=   --debug-output --trace

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHAMLIB}
LIB_DEPENDS+=	libhamlib.so:comms/hamlib
CMAKE_ARGS+=	-DUSE_HAMLIB=1
.endif

CMAKE_ARGS+=	-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wxgtk3u-3.2-config
USE_GITHUB=	yes
GH_ACCOUNT=	cjcliffe
GH_PROJECT=	CubicSDR
GH_TAGNAME=	0248e5a
#
# N.B. modem from liquidsp was renamed to modemcf Fri Nov 12, 2021
# our port liquidsp is not synced with Master hence we are stuck here for now. -db

.include <bsd.port.post.mk>
