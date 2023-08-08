PORTNAME=	gradle
PORTVERSION=	7.6.1 # because 8.0.1 breaks biology/gatk, see https://github.com/gradle/gradle/issues/25275
CATEGORIES=	devel java
MASTER_SITES=	https://downloads.gradle.org/distributions/
PKGNAMESUFFIX=	761
EXTRACT_SUFX=	-bin.zip

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Project automation tool
WWW=		https://www.gradle.org/

LICENSE=	APACHE20 BSD3CLAUSE CDDL EPL LGPL21+ MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe zip
USE_JAVA=	yes

CONFLICTS_INSTALL=	gradle gradle5 gradle6 gradle62

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
