# ex:ts=8
# Ports collection makefile for:	jcckit
# Date created:			Aug 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcckit
PORTVERSION=	1.01
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Chart Construction Kit

BROKEN=		Size mismatch

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.1+
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
