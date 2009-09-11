# New ports collection makefile for:	tinylaf
# Date created:		22 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	tinylaf
PORTVERSION=	1.4.0
CATEGORIES=	devel java
MASTER_SITES=	http://www.muntjak.de/hans/java/tinylaf/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	ayu@commun.jp
COMMENT=	A pluggable Look and Feel for Java

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

JARFILE=	${PORTNAME}.jar tinycp.jar
PORTDOCS=	readme.html gpl.txt lgpl.txt
PLIST_FILES=	${JARFILE:S|^|%%JAVAJARDIR%%/|}

do-install:
	${INSTALL_DATA} ${JARFILE:S|^|${WRKSRC}/|} ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in readme.html license/gpl.txt license/lgpl.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
