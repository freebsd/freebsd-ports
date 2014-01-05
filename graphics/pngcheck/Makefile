# Created by: will
# $FreeBSD$

PORTNAME=	pngcheck
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/png-mng/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Checks the integrity of PNG images

LICENSE=	MIT GPLv2
LICENSE_COMB=	dual

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS} -DUSE_ZLIB" LIBS="-lz"

PORTDOCS=	CHANGELOG README

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/pngcheck \
		bin/pngsplit \
		bin/png-fix-IDAT-windowsize

do-install:
.for f in pngcheck pngsplit png-fix-IDAT-windowsize
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
