# New ports collection makefile for:   aunit
# Date created:        20 Jan 2002
# Whom:                Aidan Skinner <aidan@velvet.net>
#
# $FreeBSD$
#

PORTNAME=	aunit
PORTVERSION=	1.01
CATEGORIES=	devel
MASTER_SITES=	http://libre.act-europe.fr/aunit/

MAINTAINER=	aidan@velvet.net
COMMENT=	A unit testing framework for the Ada '95 programming language

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/include/aunit
	${INSTALL_DATA} ${WRKSRC}/aunit/framework/* ${PREFIX}/include/aunit
	${INSTALL_DATA} ${WRKSRC}/aunit/text_reporter/* ${PREFIX}/include/aunit

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUnit.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
