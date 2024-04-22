PORTNAME=	kmscube
PORTVERSION=	s20230926
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Example KMS/GBM/EGL application
WWW=		https://gitlab.freedesktop.org/mesa/kmscube

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

FLAVORS=	default gstreamer
default_CONFLICTS_INSTALL=	${PORTNAME}-gstreamer
gstreamer_PKGNAMESUFFIX=	-gstreamer
gstreamer_CONFLICTS_INSTALL=	${PORTNAME}
gstreamer_OPTIONS_SLAVE=	GSTREAMER

USES=		gl meson pkgconfig
USE_GITLAB=	yes
USE_GL=		egl gbm glesv2
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_TAGNAME=	96d63eb
PLIST_FILES=	bin/${PORTNAME} \
		bin/texturator \
		${NULL}

OPTIONS_DEFINE=	GSTREAMER PNG
OPTIONS_DEFAULT=PNG
OPTIONS_SLAVE=	${${FLAVOR}_OPTIONS_SLAVE}

GSTREAMER_USES=		gnome gstreamer
GSTREAMER_USE=		GNOME=glib20
GSTREAMER_MESON_ENABLED=gstreamer

PNG_LIB_DEPENDS=	libpng.so:graphics/png

post-patch-PNG-off:
	@${REINPLACE_CMD} 's/dep_libpng.found()/false/' ${WRKSRC}/meson.build

.include <bsd.port.mk>
