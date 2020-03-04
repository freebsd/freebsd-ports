# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$
#    $MCom: ports/games/adonthell/Makefile,v 1.1 2006/10/04 20:13:33 ahze Exp $

PORTNAME=	adonthell
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Role playing game engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		gettext gmake localbase pkgconfig python sdl
USE_SDL=	mixer2 ttf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-py-debug \
		--disable-pyc \
		--with-py-libs="$$(${PYTHON_CMD}-config --ldflags)" \
		--with-python=${PYTHON_CMD}

PLIST_DIRS=	${DATADIR}/games
PLIST_FILES=	bin/adonthell \
		man/man6/adonthell.6.gz \
		${DATADIR}/modules/adonthell.py \
		${DATADIR}/modules/dialogue.py

post-patch:
	@${REINPLACE_CMD} 's,adonthell-0.3,adonthell,g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
