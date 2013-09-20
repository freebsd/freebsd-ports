# Created by: will
# $FreeBSD$

PORTNAME=	pngcheck
PORTVERSION=	2.3.0
CATEGORIES=	graphics
MASTER_SITES=	SF/png-mng/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Checks the integrity of PNG images

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS} -DUSE_ZLIB" LIBS="-lz"

PORTDOCS=	CHANGELOG README
PLIST_FILES=	bin/pngcheck

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcheck ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
