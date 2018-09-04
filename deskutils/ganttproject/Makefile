# Created by: ijliao
# $FreeBSD$

PORTNAME=	ganttproject
DISTVERSION=	2.8.8
DISTVERSIONSUFFIX=	-r2308
CATEGORIES=	deskutils java
MASTER_SITES=	https://dl.ganttproject.biz/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gantt chart based project scheduling and management tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

USES=		shebangfix zip
SHEBANG_FILES=	ganttproject
bash_CMD=	${SH}

USE_JAVA=	yes
JAVA_VERSION=	1.6+

DESKTOP_ENTRIES="GanttProject" "" "ganttproject" "ganttproject" "" ""

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${LN} -sf ../${DATADIR_REL}/ganttproject ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${RLN} ${STAGEDIR}${PREFIX}/${DATADIR_REL}/plugins-2.8.8/ganttproject/data/resources/icons/ganttproject.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/ganttproject.png

.include <bsd.port.mk>
