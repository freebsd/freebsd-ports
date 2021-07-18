PORTNAME=	yoshimi
DISTVERSION=	2.0.2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
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

USES=		cmake compiler:c++11-lang gnome ncurses pkgconfig readline
USE_GNOME=	cairo

USE_GITHUB=	yes
GH_ACCOUNT=	Yoshimi

CMAKE_SOURCE_PATH=	${WRKSRC}/src
LDFLAGS+=		-Wl,--as-needed

INSTALLS_ICONS=	yes

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
