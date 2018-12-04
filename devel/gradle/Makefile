# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	gradle
PORTVERSION=	5.0
CATEGORIES=	devel java
MASTER_SITES=	https://downloads.gradle.org/distributions/
EXTRACT_SUFX=	-bin.zip

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Project automation tool

LICENSE=	APACHE20

NO_ARCH=	yes
USES=		zip
JAVA_VERSION=	1.7+
USE_JAVA=	yes
NO_BUILD=	yes
SUB_LIST=	PORTVERSION=${PORTVERSION} \
		JAVA=${JAVA}
SUB_FILES=	gradle

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gradle ${STAGEDIR}${PREFIX}/bin/gradle
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
