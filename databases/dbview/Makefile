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

PORTCOMMENT=	View dBase III files

LIB_DEPENDS=		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=			dbview.1

USE_REINPLACE=		yes

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/db_dump.c

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/dbview ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/dbview.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/dBASE ${DOCSDIR}
.endif

.include <bsd.port.mk>
