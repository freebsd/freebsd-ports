PORTNAME=	libimagequant
PORTVERSION=	2.17.0
CATEGORIES=	graphics

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Image Quantization Library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake localbase

USE_GITHUB=	yes
GH_ACCOUNT=	ImageOptim

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/libimagequant.h \
		lib/libimagequant.a \
		lib/libimagequant.so \
		lib/libimagequant.so.0 \
		libdata/pkgconfig/imagequant.pc

.include <bsd.port.mk>
