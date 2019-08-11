# $FreeBSD$

PORTNAME=	bitmap
DISTVERSION=	g20181222
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMESUFFIX=	-graphics-library

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	db80ca605a952e6a8ccd42eba3fcc5b40fba5640.patch:-p1 # https://github.com/ArashPartow/bitmap/pull/8: Implement write_image()/read_image() functions

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

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} bitmap_test && \
		${CXX} ${CXXFLAGS} -o mk-image ${FILESDIR}/mk-image.cpp -I. && \
		./mk-image && \
		./bitmap_test && \
		${ECHO} "Tests succeeded"

.include <bsd.port.mk>
