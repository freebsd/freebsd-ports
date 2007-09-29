# ports collection makefile for:	wwl
# Date created:		1 July 2005
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	wwl
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	comms hamradio astro geography
MASTER_SITES=	http://www.db.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	${PORTNAME}+db-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Calculates distance (qrb) used in Amateur Radio

PORTDOCS=	README INSTALL
PLIST_FILES=	bin/wwl

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
