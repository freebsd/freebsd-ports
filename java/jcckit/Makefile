# ex:ts=8
# Ports collection makefile for:	jcckit
# Date created:			Aug 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcckit
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	java graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JCCKit%20${PORTVERSION}
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Chart Construction Kit

USE_ZIP=	yes
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/JCCKit
NO_BUILD=	yes
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in LICENSE.txt README.html docs
	${CP} -R ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
