# Created by: ijliao
# $FreeBSD$

PORTNAME=	ganttproject
DISTVERSION=	2.8.10
DISTVERSIONSUFFIX=	-r2364
CATEGORIES=	deskutils java
MASTER_SITES=	https://dl.ganttproject.biz/ganttproject-${DISTVERSION}/ \
		https://github.com/bardsoftware/ganttproject/releases/download/ganttproject-${DISTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Gantt chart based project scheduling and management tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		shebangfix zip
SHEBANG_FILES=	ganttproject
bash_CMD=	/bin/sh

USE_JAVA=	yes

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

DESKTOP_ENTRIES="GanttProject" "" "ganttproject" "ganttproject" "" ""

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/ganttproject
	${RLN} ${STAGEDIR}${DATADIR}/ganttproject ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${RLN} ${STAGEDIR}${DATADIR}/plugins-${DISTVERSION}/ganttproject/data/resources/icons/ganttproject.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/ganttproject.png

.include <bsd.port.mk>
