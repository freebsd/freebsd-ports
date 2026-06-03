PORTNAME=	assaultcube
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0.2
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Free, multiplayer, first-person shooter game based on the CUBE engine
WWW=		https://assault.cubers.net/

LICENSE=		ACUBE CUBE MIT OTHER
LICENSE_COMB=		multi
LICENSE_NAME_ACUBE=	AssaultCube ZLIB-like license with additions
LICENSE_NAME_CUBE=	Cube game engine ZLIB-like license with additions
LICENSE_NAME_OTHER=	various package licences
LICENSE_FILE_ACUBE=	${WRKSRC}/source/README.txt
LICENSE_FILE_CUBE=	${WRKSRC}/source/README_CUBEENGINE.txt
LICENSE_FILE_OTHER=	${WRKSRC}/docs/package_copyrights.txt
LICENSE_PERMS_ACUBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_CUBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_OTHER=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c++11-lang gmake tar:bzip2
USE_GITHUB=	yes
GH_PROJECT=	AC

LDFLAGS_i386=	-Wl,-znotext
SUB_FILES=	${PLIST_FILES:Mbin/*:T}
BUILD_WRKSRC=	${WRKSRC}/source/src

PLIST_DIRS=	${DATADIR}/packages/maps/servermaps/incoming
PORTDATA=	config packages

OPTIONS_DEFAULT=	CLIENT DEDICATED
OPTIONS_MULTI=		BUILD
OPTIONS_MULTI_BUILD=	CLIENT DEDICATED #MASTER is currently broken

CLIENT_DESC=		Build client
DEDICATED_DESC=		Build dedicated server

CLIENT_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
			libcurl.so:ftp/curl
CLIENT_USES=		desktop-file-utils gettext-runtime gl openal:al sdl \
			xorg
CLIENT_USE=		GL=gl SDL=sdl2,image2 XORG=x11
CLIENT_ALL_TARGET=	client
CLIENT_DESKTOP_ENTRIES=	"AssaultCube" "${COMMENT}" \
			"${PORTNAME}" "${PORTNAME}_client" \
			"Game;" false
CLIENT_PLIST_FILES=	bin/${PORTNAME}_client libexec/${PORTNAME}_client \
			share/pixmaps/${PORTNAME}.png
DEDICATED_ALL_TARGET=	server
DEDICATED_PLIST_FILES=	bin/${PORTNAME}_server libexec/${PORTNAME}_server

#MASTER_DESC=		Build master server
#MASTER_ALL_TARGET=	master
#MASTER_PLIST_FILES=	bin/${PORTNAME}_master libexec/${PORTNAME}_master

.include <bsd.port.pre.mk>

post-patch: .SILENT
	${REINPLACE_CMD} -e '/^CXXFLAGS=/d ; /^CXX=/d ; /^CLIENT_PCH/d ; \
		/^INCLUDES=/s|$$| -I$$(LOCALBASE)/include| ; \
		s|-I/usr/include || ; \
		s|sdl-config|$$(SDL_CONFIG)| ; \
		s|$$(USRLIB)|$$(LOCALBASE)/lib| ; \
		/^CLIENT_LIBS=/s|$$| $$(LDFLAGS) -lintl| ; \
		/^SERVER_LIBS=/s|$$| $$(LDFLAGS) -L$$(LOCALBASE)/lib|' \
		${BUILD_WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})

do-install-CLIENT-on:
	${INSTALL_DATA} ${WRKSRC}/packages/misc/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.for f in client master server
post-install-${f:S|server|DEDICATED|:tu}-on:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ac_${f} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}_${f}
.endfor

.include <bsd.port.post.mk>
