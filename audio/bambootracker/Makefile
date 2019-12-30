# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bambootracker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt:extras
DISTFILES=	${PORTNAME}-extras-${EXTRASVERSION}${EXTRACT_SUFX}:extras

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music tracker for the Yamaha YM2608 (OPNA) sound chip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang qmake qt:5 gl xorg
USE_QT=		buildtools core gui linguisttools_build multimedia network \
		widgets
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	rerrahkr
GH_PROJECT=	BambooTracker

CONFIGURE_WRKSRC=	${WRKSRC}/BambooTracker
BUILD_WRKSRC=		${WRKSRC}/BambooTracker

EXTRASVERSION=	2

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

PORTEXAMPLES=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons \
		${STAGEDIR}${MANPREFIX}/man/fr.UTF-8/man1
	${INSTALL_PROGRAM} ${WRKSRC}/BambooTracker/BambooTracker \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/BambooTracker.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/BambooTracker.fr.1 \
		${STAGEDIR}${MANPREFIX}/man/fr.UTF-8/man1
	${INSTALL_DATA} ${WRKSRC}/BambooTracker.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/BambooTracker/res/icon/icon_256x256.png \
		${STAGEDIR}${PREFIX}/share/icons/BambooTracker.png

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demos/modules/*.btm \
		${WRKDIR}/${PORTNAME}-extras-${EXTRASVERSION}/*.btm \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
