PORTNAME=	golly
DISTVERSION=	5.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Conway's Game of Life and other cellular automata
WWW=		https://golly.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../docs/License.html

USES=		gl gmake localbase python sdl
USE_GL=		gl
USE_SDL=	sdl2
USE_WX=		3.2

MAKEFILE=	makefile-gtk
BINARY_ALIAS=	g++=${CC} python3=${PYTHON_CMD} wx-config=${WX_CONFIG}

DESKTOP_ENTRIES=	"Golly" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/golly.xpm" \
			"${PREFIX}/bin/golly" \
			"Education;" \
			""

PATCH_WRKSRC=	${WRKSRC}/..
WRKSRC_SUBDIR=	gui-wx

PLIST_FILES=	bin/bgolly \
		bin/golly \
		share/pixmaps/golly.xpm
PORTDATA=	Help Patterns Rules Scripts

pre-build:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/wxmain.cpp ${WRKSRC}/wxhelp.cpp

# There is no install target at makefile-gtk
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../golly ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/../bgolly ${STAGEDIR}${PREFIX}/bin

	(cd ${WRKSRC}/.. && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/appicon.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/golly.xpm

.include <bsd.port.mk>
