PORTNAME=	fogpad
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-3
DISTVERSIONSUFFIX=	-gc52326b
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reverb effect with frozen/pitch-shifted/disintegrated reflections

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
LIB_DEPENDS=	liblo.so:audio/liblo

USES=		compiler:c++11-lib gmake gnome pkgconfig shebangfix xorg
SHEBANG_FILES=	dpf/utils/generate-ttl.sh
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmao-org
GH_PROJECT=	fogpad-port # a more recently updated fork of https://github.com/igorski/fogpad
GH_TUPLE=	DISTRHO:DPF:4e180a77ec6e93abb021b28495bd84b43498bf31:DISTRHO_DPF/dpf
USE_GNOME=	cairo
USE_XORG=	x11

CXXFLAGS+=	-I${FILESDIR}

MAKE_ARGS=	BUILD_VST2=true BUILD_DSSI=true

OPTIONS_DEFINE=		JACK
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=		yes

JACK_MAKE_ARGS=		BUILD_JACK=true
JACK_MAKE_ARGS_OFF=	BUILD_JACK=false
JACK_LIB_DEPENDS=	libjack.so:audio/jack

.include <bsd.port.mk>
