# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	gradle
PORTVERSION=	2.12
CATEGORIES=	devel java
MASTER_SITES=	https://services.gradle.org/distributions/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Project automation tool

LICENSE=	APACHE20

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-bin$$//}
SUB_LIST=	PORTVERSION=${PORTVERSION} \
		JAVA=${JAVA}
SUB_FILES=	gradle

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gradle ${STAGEDIR}${PREFIX}/bin/gradle
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
