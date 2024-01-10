PORTNAME=	optipng
DISTVERSION=	0.7.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OptiPNG/${PORTNAME}-${DISTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	Optimizer for PNG files
WWW=		https://optipng.sourceforge.net/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cpe localbase:ldflags
CPE_VENDOR=	optipng_project

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libpng \
		--with-system-zlib

PLIST_FILES=	bin/optipng \
		share/man/man1/optipng.1.gz
PORTDOCS=	history.txt optipng.man.html optipng.man.pdf optipng.man.txt \
		png_optimization.html todo.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/optipng/optipng ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/optipng/man/optipng.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
