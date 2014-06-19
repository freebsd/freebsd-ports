# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jdbm
PORTVERSION=	2.4
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Fast, simple, and transactional Java persistence engine

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PROJECTHOST=	jdbm2
LATEST_LINK=	jdbm2

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
