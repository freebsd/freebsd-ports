# New ports collection makefile for:	jcmdline
# Date created:		22 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	jcmdline
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	SF

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A Java command line processor

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

JARFILE=	${PORTNAME}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
DOCFILES=	CHANGES CREDITS README
PORTDOCS=	*

do-install:
	${INSTALL_DATA} ${JARFILE:S|.jar|-${PORTVERSION}.jar|:S|^|${WRKSRC}/|}	\
		${JAVAJARDIR}/${JARFILE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
