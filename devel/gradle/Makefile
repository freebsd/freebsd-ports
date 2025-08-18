PORTNAME=	gradle
PORTVERSION=	9.0.0
CATEGORIES=	devel java
MASTER_SITES=	https://services.gradle.org/distributions/
EXTRACT_SUFX=	-bin.zip

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Project automation tool
WWW=		https://www.gradle.org/

LICENSE=	APACHE20 BSD3CLAUSE CDDL EPL LGPL21+ MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe java zip

CONFLICTS_INSTALL=	gradle6 gradle62

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
