# New ports collection Makefile for:	gervill
# Date created:				14 October 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	gervill
PORTVERSION=	1.0
CATEGORIES=	audio java
MASTER_SITES=	SF/rasmusdsp/${PORTNAME}/Gervill%20${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A generic sound synthesizer for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	jar
JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
PORTDOCS=	*

.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadocs
.endif

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/javadocs && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
