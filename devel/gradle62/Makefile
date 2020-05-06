# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	gradle
PORTVERSION=	6.2.2
CATEGORIES=	devel java
MASTER_SITES=	https://downloads.gradle.org/distributions/
PKGNAMESUFFIX=	62
EXTRACT_SUFX=	-bin.zip

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Project automation tool

LICENSE=	APACHE20 BSD3CLAUSE CDDL EPL LGPL21+ MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zip
USE_JAVA=	yes
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	ignore:1
SUB_FILES=	gradle
SUB_LIST=	JAVA=${JAVA} \
		PORTVERSION=${PORTVERSION}
PLIST_FILES=	bin/gradle${PKGNAMESUFFIX}
PORTDATA=	*

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gradle ${STAGEDIR}${PREFIX}/bin/gradle${PKGNAMESUFFIX}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
