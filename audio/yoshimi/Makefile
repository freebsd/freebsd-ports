# $FreeBSD$

PORTNAME=	yoshimi
DISTVERSION=	1.6.0.3
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Sophisticated software synthesizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3 \
		dssi>0:audio/dssi \
		lv2>0:audio/lv2
LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libfftw3f.so:math/fftw3-float \
		libfltk.so:x11-toolkits/fltk \
		libjack.so:audio/jack \
		libmxml.so:textproc/mxml

USES=		cmake compiler:c++11-lang gnome ncurses pkgconfig readline:port
USE_GITHUB=	yes
GH_ACCOUNT=	Yoshimi
USE_GNOME=	cairo

CMAKE_SOURCE_PATH=	${WRKSRC}/src
LDFLAGS+=		-Wl,--as-needed

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
