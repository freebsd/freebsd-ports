PORTNAME=	erminej
DISTVERSION=	3.2
CATEGORIES=	biology java
MASTER_SITES=	http://home.pavlab.msl.ubc.ca/ermineJ/distributions/
DISTNAME=	ermineJ-${DISTVERSION}-generic-bundle

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Analyses of gene sets such as gene expression profiling studies
WWW=		https://erminej.msl.ubc.ca/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		zip
USE_JAVA=	yes

WRKSRC=		${WRKDIR}/ermineJ-${DISTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	ermineJ
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

do-install:
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/ermineJ ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/forehead.conf ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
