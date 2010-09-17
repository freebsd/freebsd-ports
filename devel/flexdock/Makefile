# New ports collection makefile for:   flexdock
# Date created:        25 Nov 2009
# Whom:                Otacilio de Araujo Ramos Neto <otacilio.neto@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	flexdock
PORTVERSION=	0.5.2
CATEGORIES=	devel java
MASTER_SITES=	https://flexdock.dev.java.net/files/documents/2037/152436/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	otacilio.neto@bsd.com.br
COMMENT=	Swing windowing and docking framework

USE_ZIP=	yes
USE_ANT=	yes
USE_JAVA=	yes

NO_WRKSUBDIR=	yes

ALL_TARGET=	dist

PLIST_FILES=	${JAVAJARDIR:C^${PREFIX}/^^}/${PORTNAME}.jar
PORTDOCS=	"User Guide.pdf" api

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not install on 6.x
.endif

do-install:
	${INSTALL_DATA}	${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation files..."
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/build/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
