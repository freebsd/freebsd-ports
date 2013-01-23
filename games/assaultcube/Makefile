# Created by: alepulver
# $FreeBSD$

PORTNAME=	assaultcube
PORTVERSION=	1.1.0.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/actiongame/AssaultCube%20Version%20${PORTVERSION}
DISTFILES=	AssaultCube_v${PORTVERSION}_source${EXTRACT_SUFX} \
		AssaultCube_v${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lightside@gmx.com
COMMENT=	Total conversion of the FPS game called Cube

LICENSE_COMB=	multi
LICENSE=	ACUBE CUBE MIT OTHER
LICENSE_NAME_ACUBE=	AssaultCube ZLIB-like license with additions
LICENSE_FILE_ACUBE=	${WRKSRC}/source/README.txt
LICENSE_PERMS_ACUBE=	${_LICENSE_PERMS_DEFAULT}
LICENSE_NAME_CUBE=	Cube game engine ZLIB-like license with additions
LICENSE_FILE_CUBE=	${WRKSRC}/source/README_CUBEENGINE.txt
LICENSE_PERMS_CUBE=	${_LICENSE_PERMS_DEFAULT}
LICENSE_NAME_OTHER=	various package licences
LICENSE_FILE_OTHER=	${WRKSRC}/docs/package_copyrights.txt
LICENSE_PERMS_OTHER=	dist-mirror pkg-mirror auto-accept

USE_BZIP2=	yes
USE_OPENAL=	al
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	libenet
WRKSRC=		${WRKDIR}/${PORTVERSION}
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
CONFIGURE_WRKSRC=	${WRKSRC}/source/enet
BUILD_WRKSRC=	${WRKSRC}/source/src
MAKE_JOBS_SAFE=	yes

PORTDATA=	config demos packages
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
USE_GETTEXT=	yes
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
SUB_FILES+=	${PORTNAME}_client
ACUBE_BIN+=	client

DESKTOP_ENTRIES="AssaultCube" "${COMMENT}" \
	"${DATADIR}/packages/misc/startscreen.png" "${PORTNAME}_client" \
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

do-install:
.for f in ${ACUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ac_${f} ${PREFIX}/libexec/${PORTNAME}_${f}
.endfor
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
.for f in ${ACUBE_BIN}
	@${ECHO_CMD} bin/${PORTNAME}_${f} >> ${TMPPLIST}
	@${ECHO_CMD} libexec/${PORTNAME}_${f} >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
