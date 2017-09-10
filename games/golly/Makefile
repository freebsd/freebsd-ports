# $FreeBSD$

PORTNAME=	golly
PORTVERSION=	2.7
PORTREVISION=	2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Conway's Game of Life and other cellular automata

LICENSE=	GPLv2+

USES=		compiler:c++11-lib cmake:outsource perl5 python
USE_CXXSTD=	c++11
USE_WX=		3.0

CMAKE_SOURCE_PATH=	${WRKSRC}/gui-wx

DESKTOP_ENTRIES="Golly" "${COMMENT}" "${PREFIX}/share/pixmaps/golly.xpm" \
		"${PREFIX}/bin/golly" "Education;" "true"

SUB_FILES=	golly

post-extract:
	@${FIND} ${WRKSRC} -name "._*" -delete

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/golly ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
