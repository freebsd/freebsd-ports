# Created by: johans
# $FreeBSD$

PORTNAME=	webp
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Google WebP image format conversion tool

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libtiff.so:${PORTSDIR}/graphics/tiff

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-libwebpmux \
		--enable-libwebpdemux  \
		--enable-libwebpdecoder

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes
X11_USE=	GL=glut
X11_CONFIGURE_OFF=	--with-glincludedir=/dev/null

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwebp*.so

.include <bsd.port.mk>
