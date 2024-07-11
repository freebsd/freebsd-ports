PORTNAME=	commons-collections4
DISTVERSION=	4.5.0-M2
CATEGORIES=	java devel
MASTER_SITES=	APACHE_COMMONS_BINARIES
MASTER_SITE_SUBDIR=	collections
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Classes that extend/augment the Java Collections Framework
WWW=		https://commons.apache.org/proper/commons-collections/

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	8+

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar
PORTDOCS=	apidocs

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
