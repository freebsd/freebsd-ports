# Created by: ijliao
# $FreeBSD$

PORTNAME=	ganttproject
PORTVERSION=	2.7.1
DISTVERSIONSUFFIX=	-r1924
CATEGORIES=	deskutils java
MASTER_SITES=	https://dl.ganttproject.biz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gantt chart based project scheduling and management tool

LICENSE=	GPLv3

NO_ARCH=	yes
NO_BUILD=	yes

USES=		shebangfix zip
SHEBANG_FILES=	ganttproject
bash_CMD=	${SH}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="GanttProject" "" "ganttproject" "ganttproject" "" ""

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/ganttproject
	${LN} -sf ${DATADIR}/ganttproject ${STAGEDIR}${PREFIX}/bin
.for i in 16 24 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${LN} -sf ${DATADIR}/plugins/net.sourceforge.ganttproject/data/resources/logos/icon${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/ganttproject.png
.endfor

.include <bsd.port.mk>
