# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imageworsener
PORTVERSION=	1.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://entropymine.com/imageworsener/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI utility and library for image scaling and processing

LICENSE=	MIT

OPTIONS_DEFINE=	JPEG PNG WEBP
OPTIONS_DEFAULT=JPEG PNG WEBP

CONFIGURE_ARGS=	--with-zlib-include-dir=${INCLUDEDIR} \
		--with-zlib-lib-dir=${LIBDIR}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

JPEG_CONFIGURE_OFF=	--without-jpeg
JPEG_CONFIGURE_ON=	--with-jpeg-include-dir=${LOCALBASE}/include --with-jpeg-lib-dir=${LOCALBASE}/lib
JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
PNG_CONFIGURE_OFF=	--without-png
PNG_CONFIGURE_ON=	--with-png-include-dir=${LOCALBASE}/include --with-png-lib-dir=${LOCALBASE}/lib
PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
WEBP_CONFIGURE_OFF=	--without-webp
WEBP_CONFIGURE_ON=	--with-webp-include-dir=${LOCALBASE}/include --with-webp-lib-dir=${LOCALBASE}/lib
WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp

post-build:
	@${STRIP_CMD} ${WRKSRC}/.libs/libimageworsener.so.2

.include <bsd.port.mk>
