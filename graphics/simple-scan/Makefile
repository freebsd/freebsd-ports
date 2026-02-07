PORTNAME=	simple-scan
PORTVERSION=	46.0
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple scanning utility
WWW=		https://gitlab.gnome.org/GNOME

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgusb.so:devel/libgusb \
		libsane.so:graphics/sane-backends

USES=		gettext gnome meson pkgconfig python:build shebangfix tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf gtk40 libadwaita
SHEBANG_FILES=	data/meson_compile_gschema.py
GLIB_SCHEMAS=	org.gnome.SimpleScan.gschema.xml

OPTIONS_DEFINE=	COLORD PACKAGEKIT WEBP
OPTIONS_DEFAULT=COLORD WEBP

COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord

PACKAGEKIT_DESC=	Driver installation via PackageKit
PACKAGEKIT_LIB_DEPENDS=	libpackagekit-glib2.so:ports-mgmt/packagekit

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

.for opt in COLORD PACKAGEKIT WEBP
post-patch-${opt}-off:
	@${REINPLACE_CMD} 's/^if ${opt:tl}_dep.*/if false/' \
		${WRKSRC}/src/meson.build
.endfor

.include <bsd.port.mk>
