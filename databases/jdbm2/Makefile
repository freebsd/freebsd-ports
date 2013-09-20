# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jdbm
PORTVERSION=	2.4
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A fast, simple, and transactional Java persistence engine

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PROJECTHOST=	jdbm2
LATEST_LINK=	jdbm2

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

NO_STAGE=	yes
do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/${DISTNAME}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
