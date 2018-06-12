# $FreeBSD$

PORTNAME=	poppler-data
PORTVERSION=	0.4.9
CATEGORIES=	graphics
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Poppler encoding data

USES=		pathfix
PATHFIX_MAKEFILEIN=Makefile
MAKE_ARGS=	prefix=${PREFIX}

post-install:
# Share CMap files with Ghostscript.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmap
	${LN} ${STAGEDIR}${PREFIX}/share/poppler/cMap/*/* \
		${STAGEDIR}${PREFIX}/share/cmap

.include <bsd.port.mk>
