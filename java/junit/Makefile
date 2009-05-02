# New ports collection makefile for:	JUnit
# Date created:		Jun 15 1999
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	junit
PORTVERSION=	4.6
CATEGORIES=	java devel
MASTER_SITES=	SF
#MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	A regression testing utility for use with the Java(TM) Language

USE_ZIP=	yes
USE_JAVA=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	README.html cpl-v10.html doc javadoc
.endif
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_FILES=	%%JAVAJARDIR%%/junit.jar %%DATADIR%%/src.jar
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/junit-${PORTVERSION}.jar ${JAVAJARDIR}/junit.jar
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/junit-${PORTVERSION}-src.jar ${DATADIR}/src.jar
	cd ${INSTALL_WRKSRC}/junit/samples \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.if !defined(NOPORTDOCS)
	cd ${INSTALL_WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

post-install:
	@cd ${INSTALL_WRKSRC}/junit/samples \
	  && ${FIND} -s . -type f \
	    | ${SED} 's,^\.,${EXAMPLESDIR:S,^${PREFIX}/,,},' >>${TMPPLIST} \
	  && ${FIND} -s -d . -type d \
	    | ${SED} 's,^\.,@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},' >>${TMPPLIST}

.include <bsd.port.post.mk>
