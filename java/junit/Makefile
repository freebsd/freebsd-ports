# New ports collection makefile for:	JUnit
# Date created:		Jun 15 1999
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	junit
PORTVERSION=	4.8.2
CATEGORIES=	java devel
MASTER_SITES=	http://cloud.github.com/downloads/KentBeck/junit/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	A regression testing utility for use with the Java(TM) Language

USE_ZIP=	yes
USE_JAVA=	yes
NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	README.html cpl-v10.html doc javadoc
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_FILES=	%%JAVAJARDIR%%/junit.jar %%DATADIR%%/src.jar
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/junit-${PORTVERSION}.jar ${JAVAJARDIR}/junit.jar
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/junit-${PORTVERSION}-src.jar ${DATADIR}/src.jar
.if !defined(NOPORTEXAMPLES)
	cd ${INSTALL_WRKSRC}/junit/samples \
	  && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	cd ${INSTALL_WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.mk>
