PORTNAME=	wolf-shaper
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	audio multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Waveshaper plugin with a graph editor
WWW=		https://github.com/wolf-plugins/wolf-shaper/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libpulse.so:audio/pulseaudio
LIB_DEPENDS+=	liblo.so:audio/liblo # not used other than in makefiles, see https://github.com/wolf-plugins/wolf-shaper/issues/148

USES=		gl gmake localbase pkgconfig sdl shebangfix xorg
USE_GL=		gl
USE_XORG=	x11 xext xrandr
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	wolf-plugins
GH_TUPLE=	DISTRHO:DPF:c9e9fe3:DISTRHO_DPF/dpf \
		DISTRHO:pugl:844528e:DISTRHO_DPF_pugl/dpf/dgl/src/pugl-upstream

SHEBANG_FILES=	dpf/utils/generate-ttl.sh

MAKE_ARGS=	BUILD_LV2=true
CFLAGS+=	-I${FILESDIR} # for mntent.h

OPTIONS_DEFINE=		DSSI JACK VST
OPTIONS_DEFAULT=	DSSI JACK VST
OPTIONS_SUB=		yes

DSSI_DESC=		Install the DSSI Plugin
DSSI_MAKE_ARGS=		BUILD_DSSI=true
DSSI_MAKE_ARGS_OFF=	BUILD_DSSI=false

JACK_MAKE_ARGS=		BUILD_JACK=true
JACK_MAKE_ARGS_OFF=	BUILD_JACK=false
JACK_LIB_DEPENDS=	libjack.so:audio/jack

VST_DESC=		Install the VST plugin
VST_MAKE_ARGS=		BUILD_VST2=true
VST_MAKE_ARGS_OFF=	BUILD_VST2=false

.include <bsd.port.mk>
