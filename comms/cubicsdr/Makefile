PORTNAME=	cubicsdr
DISTVERSION=	0.2.5
PORTREVISION=	7
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	SDR receiver using liquidsdr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Needs update due to Hamlib changes

RUN_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri
LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr \
		libliquid.so:comms/liquid-dsp \
		libpulse.so:audio/pulseaudio \
		libhamlib.so:comms/hamlib

USES=		cmake compiler:c++0x gl python
USE_WX=		3.1
USE_GL+=	egl glu

OPTIONS_DEFINE=	HAMLIB
HAMLIB_DESC=	Support rig control via hamlib
OPTIONS_DEFAULT=	HAMLIB

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHAMLIB}
LIB_DEPENDS+=	libhamlib.so:comms/hamlib
CMAKE_ARGS+=	-DUSE_HAMLIB=1
.endif

CMAKE_ARGS+=	-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wxgtk3u-3.1-config
USE_GITHUB=	yes
GH_ACCOUNT=	cjcliffe
GH_PROJECT=	CubicSDR
GH_TAGNAME=	9c32b97

.include <bsd.port.post.mk>
