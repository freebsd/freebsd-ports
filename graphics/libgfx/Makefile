# New ports collection makefile for:	libgfx
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgfx
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://graphics.cs.uiuc.edu/~garland/dist/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	OpenGL/FLTK development

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	${LOCALBASE}/lib/libgzstream.a:${PORTSDIR}/devel/gzstream

USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CPPFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-gzstream --with-libtiff-lzw --with-x
CFLAGS=		-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	libgfx.a

do-install:
	@${CP} -R ${WRKSRC}/include/gfx ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.a ${PREFIX}/lib/

.include <bsd.port.mk>
