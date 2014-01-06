# Created by: Douglas Carmichael <dcarmich@mcs.com>
# $FreeBSD$

PORTNAME=	photopc
PORTVERSION=	3.07
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Control cameras based on Sierra Imaging chipset and compatibles

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/epinfo \
		bin/photopc \
		include/eph_io.h \
		lib/libeph_io.a \
		man/man1/epinfo.1.gz \
		man/man1/photopc.1.gz

PORTDOCS=	README protocol.htm usage.htm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS = @CFLAGS@|CFLAGS = @CFLAGS@ -w|' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
