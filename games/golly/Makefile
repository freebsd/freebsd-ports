# $FreeBSD$

PORTNAME=	golly
PORTVERSION=	2.4
DISTVERSIONSUFFIX=	-src
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Conway's Game of Life and other cellular automata

USES=		compiler:c++11-lib cmake:outsource perl5 python
USE_WX=		3.0
WX_UNICODE=	yes

DESKTOP_ENTRIES=	"Golly" "${COMMENT}" "${PREFIX}/share/pixmaps/golly.xpm" \
			"${PREFIX}/bin/golly" "Education;" "true"

.include <bsd.port.mk>
