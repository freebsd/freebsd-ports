# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	dbview
PORTVERSION=	1.0.4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/database/proprietary

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View dBase III files

MAN1=		dbview.1
DOCS=		README dBASE

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|; \
	    s|<endian.h>|<sys/endian.h>|; \
	    /byteswap/d' \
	    ${WRKSRC}/db_dump.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dbview ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/dbview.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
