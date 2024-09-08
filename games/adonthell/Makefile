PORTNAME=	adonthell
PORTVERSION=	0.3.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SAVANNAH
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Role playing game engine
WWW=		https://adonthell.nongnu.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Fails to build, ./python_class.h:38:10: fatal error: 'eval.h' file not found
DEPRECATED=	Unmaintained in tree and broken for months
EXPIRATION_DATE=2024-09-30

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		gettext gmake localbase pkgconfig python sdl
USE_CXXSTD=	c++14
USE_SDL=	mixer2 ttf2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-py-debug \
		--disable-pyc \
		--with-py-libs="$$(${PYTHON_CMD}-config --ldflags --embed)" \
		--with-python=${PYTHON_CMD}

PLIST_DIRS=	${DATADIR}/games
PLIST_FILES=	bin/adonthell \
		share/man/man6/adonthell.6.gz \
		${DATADIR}/modules/adonthell.py \
		${DATADIR}/modules/dialogue.py

post-patch:
	@${REINPLACE_CMD} 's,adonthell-0.3,adonthell,g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
