# New ports collection makefile for:	langspec
# Date created:			18 October 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	langspec
PORTVERSION=	2.0
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.javasoft.com/docs/specs/ \
		http://java.sun.com/docs/books/jls/second_edition/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}.html
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ale@FreeBSD.org
COMMENT=	The Java Language Specification

NO_BUILD=	yes
WRKSRC=		${WRKDIR}
PORTDOCS=	*

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
