PORTNAME=	entangle
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://www.entangle-photo.org/download/sources/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Digital camera tethered control and capture program
WWW=		https://www.entangle-photo.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc \
		itstool:textproc/itstool
LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2 \
		liblcms2.so:graphics/lcms2 \
		libgexiv2.so:graphics/gexiv2 \
		libraw_r.so:graphics/libraw \
		libpeas-1.0.so:devel/libpeas
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas>0:devel/py-libpeas@${PY_FLAVOR}

USES=		compiler:c++11-lang gnome gstreamer meson pkgconfig python tar:xz xorg
USE_GNOME=	cairo gtk30 intltool introspection
USE_GSTREAMER=	core
USE_XORG=	xext
GLIB_SCHEMAS=	org.entangle-photo.manager.gschema.xml
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's,_udev,,' \
		${WRKSRC}/src/backend/entangle-camera-list.c
	@${REINPLACE_CMD} -e '/gudev_dep/d' \
		${WRKSRC}/src/backend/meson.build

.include <bsd.port.mk>
