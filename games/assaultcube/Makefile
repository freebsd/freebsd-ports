# Created by: alepulver
# $FreeBSD$

PORTNAME=	assaultcube
PORTVERSION=	1.2.0.1
CATEGORIES=	games
MASTER_SITES=	SF/actiongame/AssaultCube%20Version%20${PORTVERSION}
DISTNAME=	AssaultCube_v${PORTVERSION}

MAINTAINER=	lightside@gmx.com
COMMENT=	Total conversion of the FPS game called Cube

LICENSE_COMB=	multi
LICENSE=	ACUBE CUBE MIT OTHER
LICENSE_NAME_ACUBE=	AssaultCube ZLIB-like license with additions
LICENSE_FILE_ACUBE=	${WRKSRC}/source/README.txt
LICENSE_PERMS_ACUBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_CUBE=	Cube game engine ZLIB-like license with additions
LICENSE_FILE_CUBE=	${WRKSRC}/source/README_CUBEENGINE.txt
LICENSE_PERMS_CUBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_OTHER=	various package licences
LICENSE_FILE_OTHER=	${WRKSRC}/docs/package_copyrights.txt
LICENSE_PERMS_OTHER=	dist-mirror pkg-mirror auto-accept

USE_BZIP2=	yes
USE_OPENAL=	al
USES=	gmake
GNU_CONFIGURE=	yes
ALL_TARGET=	libenet
WRKSRC=		${WRKDIR}/AssaultCube_v${PORTVERSION}
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
CONFIGURE_WRKSRC=	${WRKSRC}/source/enet
BUILD_WRKSRC=	${WRKSRC}/source/src

PORTDATA=	config packages scripts
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	BUILD
OPTIONS_MULTI_BUILD=	CLIENT DEDICATED MASTER
OPTIONS_DEFAULT=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
MASTER_DESC=	Build master server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
USES+=		gettext
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
SUB_FILES+=	${PORTNAME}_client
ACUBE_BIN+=	client

DESKTOP_ENTRIES="AssaultCube" "${COMMENT}" \
	"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}_client" \
	"Game;" false
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	server
SUB_FILES+=	${PORTNAME}_server
ACUBE_BIN+=	server
.endif

.if ${PORT_OPTIONS:MMASTER}
ALL_TARGET+=	master
SUB_FILES+=	${PORTNAME}_master
ACUBE_BIN+=	master
.endif

pre-install: .SILENT
.if !defined(NOPORTDATA)
	# 	Current STAGEDIR doesn't create empty directories for package,
	# in case of dynamically generated TMPPLIST, where these directories exist
	${RMDIR} ${WRKSRC}/packages/maps/servermaps/incoming
.endif

do-install:
.for f in ${ACUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ac_${f} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}_${f}
.endfor
.if !defined(NOPORTDATA)
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/docs/images/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.endif

post-install:
.for f in ${ACUBE_BIN}
	@${ECHO_CMD} bin/${PORTNAME}_${f} >> ${TMPPLIST}
	@${ECHO_CMD} libexec/${PORTNAME}_${f} >> ${TMPPLIST}
.endfor
.if ${PORT_OPTIONS:MCLIENT}
	@${ECHO_CMD} share/pixmaps/${PORTNAME}.png >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
