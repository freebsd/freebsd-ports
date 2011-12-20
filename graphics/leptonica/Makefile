# New ports collection makefile for:	leptonlib
# Date created:		2009-05-20
# Whom:			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	leptonica
PORTVERSION=	1.68
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	C library for efficient image processing and image analysis operations

LIB_DEPENDS=	gif.5:${PORTSDIR}/graphics/giflib \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		webp.2:${PORTSDIR}/graphics/webp

CONFLICTS=	leptonlib-[0-9]*

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(MAINTAINER_MODE) && !defined(BATCH)
check regression-test test: build
#"display" requires the installation of graphics/xzgv
.for c in generate compare display
	@${SETENV} \
	LD_LIBRARY_PATH="${WRKSRC}/src/.libs:${LOCALBASE}/lib" \
	PATH="${PATH}:${WRKSRC}/prog" \
	${WRKSRC}/prog/alltests_reg ${c}
.endfor

.endif
.include <bsd.port.mk>
