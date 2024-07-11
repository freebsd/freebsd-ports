PORTNAME=	dpf-plugins
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of DPF-based LV2 plugins
WWW=		https://github.com/DISTRHO/DPF-Plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		liblo.so:audio/liblo \
		libprojectM.so:graphics/libprojectm \
		libpulse-simple.so:audio/pulseaudio

USES=		compiler:c++11-lang gl gmake localbase pkgconfig sdl shebangfix xorg
USE_XORG=	x11 xcursor xext xrandr
USE_GL=		gl
USE_SDL=	sdl2

SHEBANG_FILES=	dpf/utils/generate-ttl.sh

USE_GITHUB=	yes
GH_ACCOUNT=	DISTRHO
GH_PROJECT=	DPF-Plugins

CXXFLAGS+=	-I${FILESDIR}
LDFLAGS+=	-pthread
MAKE_ARGS=	LINUX=true

PLIST_SUB+=	VST_ARCH=${ARCH:S/amd64/x86_64/}

CONFLICTS_INSTALL=	nekobi-lv2 # bin/Nekobi

OPTIONS_DEFINE=		JACK
OPTIONS_DEFAULT=	JACK
OPTIONS_SUB=		yes

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

JACK_MAKE_ARGS=		HAVE_JACK=true
JACK_MAKE_ARGS_OFF=	HAVE_JACK=false
JACK_LIB_DEPENDS=	libjack.so:audio/jack

SIMD_MAKE_ENV=		SIMD_FLAGS="-mtune=generic -msse -msse2 -mfpmath=sse"

.include <bsd.port.mk>
