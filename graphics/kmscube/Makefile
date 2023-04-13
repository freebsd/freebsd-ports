PORTNAME=	kmscube
PORTVERSION=	s20230413
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Example KMS/GBM/EGL application
WWW=		https://gitlab.freedesktop.org/mesa/kmscube

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		gl meson pkgconfig
USE_GITLAB=	yes
USE_GL=		egl gbm glesv2
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_COMMIT=	cf4ec7f35521eb54d72ce0c92ce65b2249171cbd
PLIST_FILES=	bin/${PORTNAME} \
		bin/texturator \
		${NULL}

OPTIONS_DEFINE=	GSTREAMER PNG
OPTIONS_DEFAULT=PNG

GSTREAMER_USES=		gnome gstreamer
GSTREAMER_USE=		GNOME=glib20
GSTREAMER_MESON_ENABLED=gstreamer

PNG_LIB_DEPENDS=	libpng.so:graphics/png

post-patch-PNG-off:
	@${REINPLACE_CMD} 's/dep_libpng.found()/false/' ${WRKSRC}/meson.build

.include <bsd.port.mk>
