# New ports collection makefile for:   flexdock
# Date created:        25 Nov 2009
# Whom:                Otacilio de Araujo Ramos Neto <otacilio.neto@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	flexdock
PORTVERSION=	0.5.1
CATEGORIES=	devel java
MASTER_SITES=	https://flexdock.dev.java.net/files/documents/2037/52480/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	otacilio.neto@bsd.com.br
COMMENT=	Swing windowing and docking framework

USE_ZIP=	yes
USE_ANT=	yes
USE_JAVA=	yes

MAKE_ARGS=	dist

PORTDOCS=	"User Guide.pdf" api

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not install on 6.x
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${UNZIP_CMD} ${DISTDIR}/${DISTFILES} -d ${WRKSRC}

do-install:
	${INSTALL_DATA}	${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation files..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/build/docs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \;
	@cd ${WRKSRC}/build/docs && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
