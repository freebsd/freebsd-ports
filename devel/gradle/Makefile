# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	gradle
PORTVERSION=	6.8.3
CATEGORIES=	devel java
MASTER_SITES=	https://downloads.gradle.org/distributions/
EXTRACT_SUFX=	-bin.zip

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Project automation tool

LICENSE=	APACHE20 BSD3CLAUSE CDDL EPL LGPL21+ MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zip
USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	gradle
SUB_LIST=	JAVA=${JAVA} \
		PORTVERSION=${PORTVERSION}
PLIST_FILES=	bin/gradle
PORTDATA=	*

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gradle ${STAGEDIR}${PREFIX}/bin/gradle
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
