# ports collection makefile for:	wwl
# Date created:		1 July 2005
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	wwl
PORTVERSION=	1.2
CATEGORIES=	comms astro
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	db@db.net
COMMENT=	Calculates distance (qrb) used in Amateur Radio

PORTDOCS=	README INSTALL
PLIST_FILES=	bin/wwl

WRKSRC=		${WRKDIR}/wwl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/INSTALL ${DOCSDIR}
	@${ECHO} ""
	@${ECHO} "wwl docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
