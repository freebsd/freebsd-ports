PORTNAME=	yoshimi
DISTVERSION=	2.3.1.3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION:R:R}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sophisticated software synthesizer
WWW=		https://yoshimi.github.io/

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

USES=		cmake compiler:c++14-lang gnome ncurses pkgconfig readline tar:bz2
USE_GNOME=	cairo

CMAKE_SOURCE_PATH=	${WRKSRC}/src
LDFLAGS+=		-Wl,--as-needed

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# ALSA can also be enabled, but its build fails, see https://github.com/Yoshimi/yoshimi/issues/175

.include <bsd.port.mk>
