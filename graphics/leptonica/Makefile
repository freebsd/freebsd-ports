# New ports collection makefile for:	leptonlib
# Date created:		2009-05-20
# Whom:			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	leptonlib
PORTVERSION=	1.60
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	C library for efficient image processing and image analysis operations

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

PROJECTHOST=	leptonica

MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:22 aclocal:110 automake:110 autoconf:262
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I${LOCALBASE}/share/aclocal
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

post-patch:
	@${MV} ${WRKSRC}/src/makefile ${WRKSRC}/src/makefile.linux
	@${RM} ${WRKSRC}/src/jpeglib.h ${WRKSRC}/src/jmorecfg.h

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake)

run-autotools:: run-autotools-aclocal run-autotools-automake run-autotools-autoconf

.include <bsd.port.mk>
