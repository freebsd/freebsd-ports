# ports collection makefile for:	wwl
# Date created:		1 July 2005
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	wwl
PORTVERSION=	1.3
CATEGORIES=	comms hamradio astro geography
MASTER_SITES=	http://www.db.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	${PORTNAME}+db-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Calculates distance (qrb) used in Amateur Radio

CONFLICTS=	locator*
PORTDOCS=	INSTALL
PLIST_FILES=	bin/wwl bin/locator
MAN1=		wwl.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wwl ${PREFIX}/bin
	${RM} -f ${PREFIX}/bin/locator
	${LN} ${PREFIX}/bin/wwl ${PREFIX}/bin/locator
	${INSTALL_DATA} ${WRKSRC}/wwl.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif

.include <bsd.port.mk>
