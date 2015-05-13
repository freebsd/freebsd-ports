# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-collections
PORTVERSION=	3.2.1
CATEGORIES=	java devel
MASTER_SITES=	APACHE_COMMONS_SOURCE
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Classes that extend/augment the Java Collections Framework

USE_JAVA=	yes
USE_ANT=	yes

ALL_TARGET=	jar
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
OTHERDOCS=	DEVELOPERS-GUIDE.html LICENSE.txt PROPOSAL.html README.txt RELEASE-NOTES.html
PORTDOCS=	apidocs ${OTHERDOCS}

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	javadoc

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/docs && \
		${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
