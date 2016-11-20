# Created by: johans
# $FreeBSD$

PORTNAME=	webp
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.webmproject.org/releases/webp/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google WebP image format conversion tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

CONFIGURE_ARGS=	--enable-libwebpdecoder \
		--enable-libwebpdemux  \
		--enable-libwebpmux \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		compiler:c11 jpeg libtool localbase

X11_CONFIGURE_OFF=	build_vwebp=no
X11_CONFIGURE_ON=	build_vwebp=yes
X11_USE=		GL=glut

post-patch:
	@${REINPLACE_CMD} '/build_vwebp=yes/d' ${WRKSRC}/configure

.include <bsd.port.mk>
