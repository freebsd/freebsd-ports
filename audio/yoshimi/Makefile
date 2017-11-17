# $FreeBSD$

PORTNAME=	yoshimi
DISTVERSION=	1.5.4.1-28
DISTVERSIONSUFFIX=	-g31291f0d
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

USES=		cmake:outsource ncurses pkgconfig readline:port
USE_GITHUB=	yes
USE_GNOME=	cairo
USE_GL=		gl glu
USE_XORG=	x11 ice sm xext

CMAKE_SOURCE_PATH=	${WRKSRC}/src
INSTALLS_ICONS=	yes

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/share/yoshimi/yoshimi-user-manual.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
