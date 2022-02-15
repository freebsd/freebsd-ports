PORTNAME=	cardinal
DISTVERSION=	22.02
CATEGORIES=	audio
MASTER_SITES=	https://github.com/DISTRHO/Cardinal/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Plugin wrapper around VCV Rack

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/FuzzySearchDatabase.hpp:textproc/fuzzysearchdatabase \
		bash:shells/bash
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libjansson.so:devel/jansson \
		liblo.so:audio/liblo \
		libpffft.so:math/pffft \
		libpulse-simple.so:audio/pulseaudio \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libspeexdsp.so:audio/speexdsp

USES=		compiler:c++11-lang gl gmake libarchive localbase:ldflags pkgconfig python shebangfix tar:xz xorg
USE_XORG=	x11 xcursor xext xrandr
USE_GL=		gl

SHEBANG_GLOB=	*.sh

CXXFLAGS+=	-I${LOCALBASE}/include/pffft
LDFLAGS+=	-lpffft

MAKE_ENV=	LD_PRELOAD=/usr/lib/libpthread.so # workaround for https://github.com/DISTRHO/Cardinal/issues/128#issuecomment-1030817359
MAKE_ARGS=	SYSDEPS=true

BINARY_ALIAS=	gcc-ar=ar \
		python3=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS LTO

PORTDOCS=	*

LTO_MAKE_ARGS=	WITH_LTO=true
LTO_BROKEN=	Fails to build with LTO because it is gcc-centered

.include <bsd.port.mk>
