# New ports collection makefile for:	langspec
# Date created:			18 October 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	langspec
PORTVERSION=	3.0
CATEGORIES=	java
MASTER_SITES=	http://java.sun.com/docs/books/jls/download/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	The Java Language Specification

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}
PORTDOCS=	*

.if defined(NOPORTDOCS)
IGNORE=		installs *only* documentation, unset NOPORTDOCS
.endif

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
