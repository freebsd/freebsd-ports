PORTNAME=	webp
PORTVERSION=	1.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.webmproject.org/releases/webp/ \
		https://storage.googleapis.com/downloads.webmproject.org/releases/webp/
DISTNAME=	libwebp-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google WebP image format conversion tool
WWW=		https://developers.google.com/speed/webp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 libtool localbase

CONFIGURE_ARGS=	--enable-libwebpdecoder \
		--enable-libwebpdemux  \
		--enable-libwebpmux \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	IMGCONV X11
OPTIONS_DEFAULT=IMGCONV
OPTIONS_SUB=	yes
IMGCONV_DESC=		Install converters to/from WebP

IMGCONV_CONFIGURE_OFF=	build_cwebp=no build_dwebp=no build_gif2webp=no build_img2webp=no
IMGCONV_CONFIGURE_ON=	build_cwebp=yes build_dwebp=yes build_gif2webp=yes build_img2webp=yes
IMGCONV_LIB_DEPENDS=	libgif.so:graphics/giflib \
			libpng.so:graphics/png \
			libtiff.so:graphics/tiff
IMGCONV_USES=		jpeg
X11_CONFIGURE_OFF=	build_vwebp=no
X11_CONFIGURE_ON=	build_vwebp=yes
X11_USE=		GL=glut
X11_USES=		gl

.include <bsd.port.mk>
