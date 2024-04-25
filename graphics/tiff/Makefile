PORTNAME=	tiff
DISTVERSION=	4.6.0
CATEGORIES=	graphics
MASTER_SITES=	https://download.osgeo.org/libtiff/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Tools and library routines for working with TIFF images
WWW=		http://www.simplesystems.org/libtiff/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate \
		libjbig.so:graphics/jbigkit \
		libLerc.so:graphics/lerc \
		libzstd.so:archivers/zstd

USES=		cpe jpeg libtool localbase pathfix tar:xz
CPE_PRODUCT=	libtiff
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-sphinx \
		--disable-webp

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

LDFLAGS+=	-Wl,--undefined-version

DOCSDIR=	${PREFIX}/share/doc/tiff-${DISTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
