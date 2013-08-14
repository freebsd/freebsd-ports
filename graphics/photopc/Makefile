# Created by:			Douglas Carmichael <dcarmich@mcs.com>
#
# $FreeBSD$

PORTNAME=	photopc
PORTVERSION=	3.07
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Control cameras based on Sierra Imaging chipset and compatibles

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/epinfo \
		bin/photopc \
		include/eph_io.h \
		lib/libeph_io.a

MAN1=		epinfo.1 photopc.1

PORTDOCS=	README protocol.htm usage.htm

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
