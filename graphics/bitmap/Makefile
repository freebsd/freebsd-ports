# $FreeBSD$

PORTNAME=	bitmap
DISTVERSION=	g20181222
CATEGORIES=	graphics
PKGNAMESUFFIX=	-graphics-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimalistic library manipulating 24-bit per pixel bitmap images

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ArashPartow
GH_TAGNAME=	b02297f

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/bitmap_image.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/bitmap_image.hpp ${STAGEDIR}${PREFIX}/include

do-test: # tests failure reported to the author: Error - Failed to open 'image.bmp'
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} bitmap_test && \
		./bitmap_test

.include <bsd.port.mk>
