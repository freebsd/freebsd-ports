PORTNAME=	log4j2
PORTVERSION=	2.22.0
CATEGORIES=	devel java
MASTER_SITES=	APACHE/logging/log4j/${PORTVERSION}
PKGNAMEPREFIX=	apache-
DISTNAME=	apache-log4j-${PORTVERSION}-bin

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Fast and flexible logging library for Java
WWW=		https://logging.apache.org/log4j/2.x/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe zip

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	8+
NO_BUILD=	yes
NO_ARCH=	yes
CPE_VENDOR=	apache
CPE_PRODUCT=	log4j

PORTDOCS=	NOTICE.txt RELEASE-NOTES.adoc

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	cd ${WRKSRC} && \
	for j in `${FIND} . -name "*${PORTVERSION}.jar"`; do \
		${INSTALL_DATA} $$j ${STAGEDIR}${JAVAJARDIR}/`echo $$j | ${SED} -e 's|-${PORTVERSION}||'`; \
	done

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
