# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$
#    $MCom: ports/games/adonthell/Makefile,v 1.1 2006/10/04 20:13:33 ahze Exp $

PORTNAME=	adonthell
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
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
		--with-py-libs="$$(${PYTHON_CMD}-config --ldflags ${_PY_EMBED})" \
		--with-python=${PYTHON_CMD}

PLIST_DIRS=	${DATADIR}/games
PLIST_FILES=	bin/adonthell \
		man/man6/adonthell.6.gz \
		${DATADIR}/modules/adonthell.py \
		${DATADIR}/modules/dialogue.py

.include <bsd.port.pre.mk>

# The "--embed" flag was introduced with Python 3.8 and is required because
# C extensions are no longer linked to libpython since Python 3.8 and onwards.
#
# See also https://bugs.python.org/issue36721 for reference.
.if ${PYTHON_REL} >= 3800
_PY_EMBED=	--embed
.endif

post-patch:
	@${REINPLACE_CMD} 's,adonthell-0.3,adonthell,g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
