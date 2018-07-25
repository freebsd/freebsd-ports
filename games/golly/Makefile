# $FreeBSD$

PORTNAME=	golly
PORTVERSION=	3.2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Conway's Game of Life and other cellular automata

LICENSE=	GPLv2+

USES=		compiler:c++11-lib python:2.7
USE_GL=		gl glu
USE_WX=		3.0+

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG:T}
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES=	"Golly" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/golly.xpm" \
			"${PREFIX}/bin/golly" \
			"Education;" \
			""
WRKSRC_SUBDIR=	gui-wx/configure

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../icons/appicon.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/golly.xpm

.include <bsd.port.mk>
