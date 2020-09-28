# Created by: ijliao
# $FreeBSD$

PORTNAME=	ganttproject
DISTVERSION=	2.8.11
DISTVERSIONSUFFIX=	-r2393
CATEGORIES=	deskutils java
MASTER_SITES=	https://github.com/bardsoftware/ganttproject/releases/download/ganttproject-${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gantt chart based project scheduling and management tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils shebangfix zip
USE_JAVA=	yes
SHEBANG_FILES=	ganttproject
bash_CMD=	/bin/sh

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

do-install:
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/ganttproject
	${RLN} ${STAGEDIR}${DATADIR}/ganttproject ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${RLN} ${STAGEDIR}${DATADIR}/plugins/${DISTVERSION}/ganttproject/data/resources/icons/ganttproject.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/ganttproject.png
	${INSTALL_DATA} ${FILESDIR}/ganttproject.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
