# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	gradle
PORTVERSION=	4.10.3
CATEGORIES=	devel java
MASTER_SITES=	https://downloads.gradle.org/distributions/
PKGNAMESUFFIX=	4
EXTRACT_SUFX=	-bin.zip

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Project automation tool

LICENSE=	APACHE20

USES=		zip
USE_JAVA=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	PKGNAMESUFFIX=${PKGNAMESUFFIX}
PORTSCOUT=	ignore:1
SUB_LIST=	PORTVERSION=${PORTVERSION} \
		JAVA=${JAVA}
SUB_FILES=	gradle

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gradle ${STAGEDIR}${PREFIX}/bin/gradle${PKGNAMESUFFIX}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
