PORTNAME=	dbview
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SUNSITE/apps/database/proprietary

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View dBase III files
WWW=		https://www.infodrom.org/projects/dbview/

LICENSE=	GPLv2+

PLIST_FILES=	bin/dbview share/man/man1/dbview.1.gz
PORTDOCS=	README dBASE

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|; \
		s|<endian.h>|<sys/endian.h>|; \
		/byteswap/d' \
		${WRKSRC}/db_dump.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dbview.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
