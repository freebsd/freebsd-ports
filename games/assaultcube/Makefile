# Created by: alepulver
# $FreeBSD$

PORTNAME=	assaultcube
PORTVERSION=	1.2.0.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/actiongame/AssaultCube%20Version%20${PORTVERSION}
DISTNAME=	AssaultCube_v${PORTVERSION}

MAINTAINER=	lightside@gmx.com
COMMENT=	Total conversion of the FPS game called Cube

LICENSE=	ACUBE CUBE MIT OTHER
LICENSE_COMB=	multi
LICENSE_NAME_ACUBE=	AssaultCube ZLIB-like license with additions
LICENSE_NAME_CUBE=	Cube game engine ZLIB-like license with additions
LICENSE_NAME_OTHER=	various package licences
LICENSE_FILE_ACUBE=	${WRKSRC}/source/README.txt
LICENSE_FILE_CUBE=	${WRKSRC}/source/README_CUBEENGINE.txt
LICENSE_FILE_OTHER=	${WRKSRC}/docs/package_copyrights.txt
LICENSE_PERMS_ACUBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_CUBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_OTHER=	dist-mirror pkg-mirror auto-accept

USES=		gmake tar:bzip2
LLD_UNSAFE=	yes
WRKSRC=		${WRKDIR}/AssaultCube_v${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/source/src
SUB_FILES=	${PLIST_FILES:Mbin/*:T}

PORTDATA=	config packages scripts
PORTDOCS=	*
PLIST_DIRS=	${DATADIR}/packages/maps/servermaps/incoming

OPTIONS_DEFINE=	DOCS PORT_ENET
OPTIONS_MULTI=	BUILD
OPTIONS_MULTI_BUILD=	CLIENT DEDICATED MASTER
OPTIONS_DEFAULT=	CLIENT DEDICATED

CLIENT_DESC=	Build client
CLIENT_USES=		compiler:c++11-lang gettext-runtime gl openal:al sdl \
			xorg
CLIENT_USE=		GL=gl SDL=image,sdl XORG=x11
CLIENT_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
			libcurl.so:ftp/curl
CLIENT_ALL_TARGET=	client
CLIENT_DESKTOP_ENTRIES=	"AssaultCube" "${COMMENT}" \
	"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}_client" \
	"Game;" false
CLIENT_PLIST_FILES=	bin/${PORTNAME}_client libexec/${PORTNAME}_client \
			share/pixmaps/${PORTNAME}.png
DEDICATED_DESC=	Build dedicated server
DEDICATED_ALL_TARGET=	server
DEDICATED_PLIST_FILES=	bin/${PORTNAME}_server libexec/${PORTNAME}_server
MASTER_DESC=	Build master server
MASTER_ALL_TARGET=	master
MASTER_PLIST_FILES=	bin/${PORTNAME}_master libexec/${PORTNAME}_master
PORT_ENET_DESC=	Use libenet from net/enet
PORT_ENET_CONFIGURE_OFF=	--enable-shared=no --enable-static=yes
PORT_ENET_LIB_DEPENDS=	libenet.so:net/enet
PORT_ENET_VARS_OFF=	GNU_CONFIGURE=yes CONFIGURE_WRKSRC="${WRKSRC}/source/enet"

post-patch: .SILENT
	${REINPLACE_CMD} -e '/^CXXFLAGS=/d ; /^CXX=/d ; /^CLIENT_PCH/d ; \
		/^INCLUDES=/s|$$| -I$$(LOCALBASE)/include| ; \
		s|-I/usr/include || ; \
		s|sdl-config|$$(SDL_CONFIG)| ; \
		s|$$(USRLIB)|$$(LOCALBASE)/lib| ; \
		/^CLIENT_LIBS=/s|$$| $$(LDFLAGS) -lintl| ; \
		/^SERVER_LIBS=/s|$$| $$(LDFLAGS) -L$$(LOCALBASE)/lib|' \
		${BUILD_WRKSRC}/Makefile

post-patch-PORT_ENET-on:
	@${REINPLACE_CMD} -i '.port_enet.bak' -e 's/libenet // ; \
		s|-I\.\./enet/include|| ; \
		s|-L\.\./enet/\.libs||' \
		${BUILD_WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-CLIENT-on:
	${INSTALL_DATA} ${WRKSRC}/docs/images/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.for f in client master server
post-install-${f:S|server|DEDICATED|:tu}-on:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ac_${f} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}_${f}
.endfor

.include <bsd.port.mk>
