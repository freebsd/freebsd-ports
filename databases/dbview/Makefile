# New ports collection makefile for:	dbview
# Date created:				7 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		dbview
PORTVERSION=		1.0.3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			ftp://ftp.infodrom.north.de/pub/Linux/Devel/dbview/
MASTER_SITE_SUBDIR=	apps/database/proprietary

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=			dbview.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/dbview ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/dbview.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/dbview
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dbview
	@ ${INSTALL_DATA} ${WRKSRC}/dBASE ${PREFIX}/share/doc/dbview
.endif

.include <bsd.port.mk>
