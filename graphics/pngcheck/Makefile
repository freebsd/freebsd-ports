PORTNAME=	pngcheck
PORTVERSION=	3.0.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libpng.org/pub/png/src/ \
		https://www.cyberbotx.com/pngcheck/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Checks the integrity of PNG images

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/gpl/COPYING

USES=		cpe
CPE_VENDOR=	libpng

MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS} -DUSE_ZLIB" LIBS="-lz"

PLIST_FILES=	bin/png-fix-IDAT-windowsize \
		bin/pngcheck \
		bin/pngsplit
PORTDOCS=	CHANGELOG README

OPTIONS_DEFINE=	DOCS

do-install:
.for f in pngcheck pngsplit png-fix-IDAT-windowsize
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
