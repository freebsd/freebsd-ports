# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bambootracker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt:extras
DISTFILES=	${PORTNAME}-extras-${EXTRASVERSION}${EXTRACT_SUFX}:extras

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music tracker for the Yamaha YM2608 (OPNA) sound chip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmake qt:5 gl
USE_QT=		buildtools core gui multimedia network widgets
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	rerrahkr
GH_PROJECT=	BambooTracker

CONFIGURE_WRKSRC=	${WRKSRC}/BambooTracker
BUILD_WRKSRC=		${WRKSRC}/BambooTracker

EXTRASVERSION=	1

OPTIONS_DEFINE=	EXAMPLES

PLIST_FILES=	bin/BambooTracker man/man1/BambooTracker.1.gz \
		share/applications/BambooTracker.desktop \
		share/icons/BambooTracker.png
PORTEXAMPLES=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_PROGRAM} ${WRKSRC}/BambooTracker/BambooTracker \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/BambooTracker.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/BambooTracker.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}-extras-${EXTRASVERSION}/BambooTracker.png \
		${STAGEDIR}${PREFIX}/share/icons

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}-extras-${EXTRASVERSION}/majfant2quieter.btm \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
