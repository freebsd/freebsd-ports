# Created by: will
# $FreeBSD$

PORTNAME=	pngcheck
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/png-mng/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checks the integrity of PNG images

LICENSE=	MIT GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/gpl/COPYING

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS} -DUSE_ZLIB" LIBS="-lz"

PORTDOCS=	CHANGELOG README

PLIST_FILES=	bin/pngcheck \
		bin/pngsplit \
		bin/png-fix-IDAT-windowsize

OPTIONS_DEFINE=	DOCS

do-install:
.for f in pngcheck pngsplit png-fix-IDAT-windowsize
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
