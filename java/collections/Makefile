# New ports collection makefile for:    JDK1.1 Collections package
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	collections
PORTVERSION=	1.1
CATEGORIES=	java
DISTNAME=	collections1_1
EXTRACT_SUFX=	.zip

MAINTAINER=	java@freebsd.org
COMMENT=	JDK1.2 Collections' API for JDK1.1 environments

USE_JAVA=	yes
JAVA_VERSION=	1.1
JAVA_RUN=	jre

USE_ZIP=	YES

WRKSRC=		${WRKDIR}/1.1collections
NO_BUILD=	yes
NO_CDROM=	"See the license"

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.TXT README.TXT javadoc
.endif
JARFILE=	collections.jar
PLIST_FILES+=	${JAVAJARDIR:S,^${PREFIX}/,,}/${JARFILE}

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	"You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from http://java.sun.com/products/archive/javabeans/infobus/downloads.html and place it in ${DISTDIR} then run make again"
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${CP} ${WRKSRC}/lib/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${CP} -R ${WRKSRC}/doc/${DOCFILE} ${DOCSDIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
