PORTNAME=	optipng
DISTVERSION=	7.9.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OptiPNG/${PORTNAME}-${DISTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	Optimizer for PNG files
WWW=		https://optipng.sourceforge.net/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cpe cmake
CPE_VENDOR=	optipng_project

CMAKE_ON=	OPTIPNG_USE_SYSTEM_PNG OPTIPNG_USE_SYSTEM_ZLIB

PLIST_FILES=	bin/optipng \
		share/man/man1/optipng.1.gz
PORTDOCS=	history.txt optipng.man1.html optipng.man1.txt \
		png_optimization.html todo.txt

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
