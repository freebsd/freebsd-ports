# $FreeBSD$

PORTNAME=	golly
PORTVERSION=	2.4
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Conway's Game of Life and other cellular automata

USES=		cmake:outsource perl5
USE_PYTHON=	yes
USE_WX=		2.8+

DESKTOP_ENTRIES=	"Golly" "${COMMENT}" "${PREFIX}/share/pixmaps/golly.xpm" \
			"${PREFIX}/bin/golly" "Education;" "true"

.include <bsd.port.mk>
