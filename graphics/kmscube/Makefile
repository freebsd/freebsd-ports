# $FreeBSD$

PORTNAME=	kmscube
PORTVERSION=	s20201028
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Example KMS/GBM/EGL application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		gl meson pkgconfig
USE_GITLAB=	yes
USE_GL=		egl gbm glesv2
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_COMMIT=	e6386d1b99366ea7559438c0d3abd2ae2d6d61ac
PLIST_FILES=	bin/${PORTNAME} \
		bin/texturator \
		${NULL}

OPTIONS_DEFINE=	GSTREAMER PNG
OPTIONS_DEFAULT=PNG

GSTREAMER_USES=		gnome
GSTREAMER_USE=		GNOME=glib20 GSTREAMER1=yes
GSTREAMER_MESON_ENABLED=gstreamer

PNG_LIB_DEPENDS=	libpng.so:graphics/png

post-patch-PNG-off:
	@${REINPLACE_CMD} 's/dep_libpng.found()/false/' ${WRKSRC}/meson.build

.include <bsd.port.mk>
