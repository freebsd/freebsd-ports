PORTNAME=	openomf
DISTVERSION=	0.8.3
CATEGORIES=	games
MASTER_SITES=	http://www.omf2097.com/pub/files/omf/:data
DISTFILES=	omf2097.rar:data

MAINTAINER=	devel@stasyan.com
COMMENT=	Rewritten engine for One Must Fall 2097
WWW=		https://www.openomf.org/ \
		https://github.com/omf2097/openomf/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libenet.so:net/enet \
		libepoxy.so:graphics/libepoxy \
		libminiupnpc.so:net/miniupnpc \
		libnatpmp.so:net/libnatpmp \
		libopusfile.so:audio/opusfile \
		libpng.so:graphics/png \
		libxmp.so:audio/libxmp

USES=		cmake compiler:c++11-lang sdl
USE_GITHUB=	yes
GH_ACCOUNT=	omf2097
USE_SDL=	mixer2 sdl2

LDFLAGS_i386=	-Wl,-znotext

DESKTOP_ENTRIES=	"OpenOMF" "" \
			"${DATADIR}/${PORTNAME}.png " \
			"${PORTNAME}" "Game;ArcadeGame;" false

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/resources/pathmanager.c
	${REINPLACE_CMD} -e 's|share/games/openomf|share/openomf|g' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/cmake-scripts/BuildLanguages.cmake

post-install:
	(cd ${WRKDIR}/OMF2097 && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/resources && \
		${INSTALL_DATA} DANISH.TXT DANISH2.TXT ENGLISH2.TXT GERMAN2.TXT \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
