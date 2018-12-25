# $FreeBSD$

PORTNAME=	yoshimi
DISTVERSION=	1.5.7
CATEGORIES=	audio

MAINTAINER=	hello@blubee.me
COMMENT=	Sophisticated software synthesizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		dssi>0:audio/dssi \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libfftw3f.so:math/fftw3-float \
		libfltk.so:x11-toolkits/fltk \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libjack.so:audio/jack \
		libmxml.so:textproc/mxml

BROKEN_aarch64=		fails to compile: c++: warning: argument unused during compilation: '-msse'
BROKEN_armv6=		fails to compile: c++: warning: argument unused during compilation: '-msse'
BROKEN_armv7=		fails to compile: c++: warning: argument unused during compilation: '-msse'

USES=		cmake ncurses pkgconfig readline:port
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_GL=		gl glu
USE_XORG=	x11 ice sm xext

CMAKE_SOURCE_PATH=	${WRKSRC}/src
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
