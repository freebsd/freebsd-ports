# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	steelstorm
DISTVERSION=	beta-r1591
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Old school top down arcade shooter

LICENSE=	GPLv2 CC-BY-NC-SA-3.0 EULA
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/gpl-2.txt
LICENSE_FILE_CC-BY-NC-SA-3.0=	${WRKSRC}/cc-by-nc-sa-3.txt
LICENSE_NAME_EULA=	Steel storm episode 1 limited user software license agreement
LICENSE_PERMS_EULA=	# none
LICENSE_FILE_EULA=	${WRKSRC}/license.txt
MANUAL_PACKAGE_BUILD=	needs interactive license confirmation

USES=		gl
USE_GL=		gl

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/engine_source
MAKEFILE=	BSDmakefile
MAKE_ENV=	STRIP="${STRIP_CMD}"
ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=yes

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=	CLIENT DEDICATED
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS CLIENT DEDICATED

CLIENT_DESC=	Build client
DEDICATED_DESC=	Dedicated server

CLIENT_ALL_TARGET=	cl-release
CLIENT_USES=		xorg
CLIENT_USE=		XORG=x11,xext,xpm,xxf86dga,xxf86vm
CLIENT_PLIST_FILES=	bin/${PORTNAME}

DEDICATED_ALL_TARGET=	sv-release
DEDICATED_PLIST_FILES=	bin/${PORTNAME}-dedicated

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${BUILD_WRKSRC}/BSDmakefile ${BUILD_WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e 's|"gamedata"|"${DATADIR}"|' \
		${BUILD_WRKSRC}/common.c

post-patch-OPTIMIZED_CFLAGS-off:
	@${REINPLACE_CMD} -e '/^OPTIM_RELEASE=/ d' \
		${BUILD_WRKSRC}/makefile.inc

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gamedata/ssgamedata000001.pk3 ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

do-install-CLIENT-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-glx ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DEDICATED-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/darkplaces-dedicated ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-dedicated

.include <bsd.port.mk>
