PORTNAME=	mesa-demos
PORTVERSION=	8.4.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/demos/ #${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa
WWW=		https://www.mesa3d.org/

LICENSE=	MIT

CONFLICTS_INSTALL=	glx-utils

USES=		gmake gl localbase pkgconfig tar:bzip2 xorg
GNU_CONFIGURE=	yes
USE_GL=		egl gl glesv2 glew glu glut
USE_XORG=	xorgproto x11 xdamage xext xfixes xi xxf86vm

CONFIGURE_ARGS+=--disable-gles1 --disable-osmesa --disable-vg --disable-wayland \
		--with-system-data-files

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-stage:
	# bitmap program conflicts with x11/bitmap
	${MV} ${STAGEDIR}/${PREFIX}/bin/bitmap ${STAGEDIR}/${PREFIX}/bin/bitmap_demo

.include <bsd.port.mk>
