# $FreeBSD$

PORTNAME=	cubicsdr
DISTVERSION=	0.2.5
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	SDR receiver using liquidsdr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/lib/libEGL.so:graphics/mesa-libs \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri
LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr \
		libliquid.so:comms/liquid-dsp \
		libpulse.so:audio/pulseaudio \
		libhamlib.so:comms/hamlib \
		libEGL.so:graphics/mesa-libs \
		libwx_gtk3u_core-3.1.so:x11-toolkits/wxgtk31

USES=		cmake gl python
USE_GL+=	glu

OPTIONS_DEFINE=	HAMLIB
HAMLIB_DESC=	Support rig control via hamlib
OPTIONS_DEFAULT=	HAMLIB

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHAMLIB}
LIB_DEPENDS+=	libhamlib.so:comms/hamlib
CMAKE_ARGS+=	-DUSE_HAMLIB=1
.endif

CMAKE_ARGS+=	-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wxgtk3u-3.1-config
# if Only I could just do
#USE_WX=		3.1
#WX_COMPS=	wx
USE_GITHUB=	yes
GH_ACCOUNT=	cjcliffe
GH_PROJECT=	CubicSDR

.include <bsd.port.post.mk>
