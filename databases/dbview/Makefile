# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	dbview
PORTVERSION=	1.0.4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/database/proprietary

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View dBase III files

PLIST_FILES=	bin/dbview man/man1/dbview.1.gz
PORTDOCS=	README dBASE

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|; \
	    s|<endian.h>|<sys/endian.h>|; \
	    /byteswap/d' \
	    ${WRKSRC}/db_dump.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dbview.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
