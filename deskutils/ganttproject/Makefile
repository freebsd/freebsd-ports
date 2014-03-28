# Created by: ijliao
# $FreeBSD$

PORTNAME=	ganttproject
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	deskutils java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-r1544

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Gantt chart based project scheduling and management tool

LICENSE=	GPLv3

USES=		shebangfix zip
SHEBANG_FILES=	ganttproject
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${CHMOD} 0755 ${STAGEDIR}${DATADIR}/ganttproject
	${LN} -sf ${DATADIR}/ganttproject ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
