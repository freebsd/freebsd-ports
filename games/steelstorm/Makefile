# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	steelstorm
DISTVERSION=	beta-r1591
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Old school top down arcade shooter

LICENSE=	GPLv2 CCbyNCSA3 EULA
LICENSE_COMB=	multi

LICENSE_FILE_GPLv2=	${WRKSRC}/gpl-2.txt

LICENSE_NAME_CCbyNCSA3=	Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept
LICENSE_FILE_CCbyNCSA3=	${WRKSRC}/cc-by-nc-sa-3.txt

LICENSE_NAME_EULA=	Steel storm episode 1 limited user software license agreement
LICENSE_PERMS_EULA=	# none
LICENSE_FILE_EULA=	${WRKSRC}/license.txt
MANUAL_PACKAGE_BUILD=	needs interactive license confirmation

USE_GL=		gl
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/engine_source
MAKEFILE=	BSDmakefile
MAKE_ENV=	STRIP="${STRIP_CMD}"
ALL_TARGET=	# empty

PORTDOCS=	README.txt

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC=	Dedicated server
FLAVOR_DESC=	Executable Selection

OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS CLIENT DEDICATED

PLIST_FILES=	%%DATADIR%%/ssgamedata000001.pk3
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
ALL_TARGET+=	cl-release
USE_XORG+=	x11 xpm xext xxf86dga xxf86vm
PLIST_FILES+=	bin/steelstorm
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	sv-release
PLIST_FILES+=	bin/steelstorm-dedicated
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${BUILD_WRKSRC}/BSDmakefile ${BUILD_WRKSRC}/makefile.inc
.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} -e '/^OPTIM_RELEASE=/ d' \
		${BUILD_WRKSRC}/makefile.inc
.endif
	@${REINPLACE_CMD} -e 's|"gamedata"|"${DATADIR}"|' \
		${BUILD_WRKSRC}/common.c

do-install:
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-glx ${PREFIX}/bin/steelstorm
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-dedicated ${PREFIX}/bin/steelstorm-dedicated
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gamedata/ssgamedata000001.pk3 ${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
