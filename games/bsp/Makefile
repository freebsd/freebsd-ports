# New ports collection makefile for:	bsp
# Date created:			22 April 2002
# Whom:				Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	bsp
PORTVERSION=	5.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	doombsp

MAINTAINER=	chris@unixpages.org

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
