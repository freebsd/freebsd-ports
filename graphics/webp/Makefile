# Created by: johans
# $FreeBSD$

PORTNAME=	webp
PORTVERSION=	0.4.1
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.webmproject.org/releases/webp/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google WebP image format conversion tool

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-libwebpdecoder \
		--enable-libwebpdemux  \
		--enable-libwebpmux \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes
USES=		compiler:c11 libtool

X11_CONFIGURE_OFF=	build_vwebp=no
X11_CONFIGURE_ON=	build_vwebp=yes
X11_USE=		GL=glut

post-patch:
	@${REINPLACE_CMD} '/build_vwebp=yes/d' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwebp*.so

.include <bsd.port.mk>
