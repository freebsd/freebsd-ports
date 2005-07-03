# ports collection makefile for:	locator
# Date created:		30 June 2005
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	locator
PORTVERSION=	0.1
CATEGORIES=	comms astro
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	db@db.net
COMMENT=	Grid square calculator program used in Amateur Radio and GPS work

PORTDOCS=	README
PLIST_FILES=	bin/locator

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/locator ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO} ""
	@${ECHO} "locator README installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
