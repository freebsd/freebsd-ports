PORTNAME=	eog-plugins
DISTVERSION=	44.1
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	eog:graphics/eog
LIB_DEPENDS=	libgdata.so:devel/libgdata \
		libgoa-1.0.so:net/gnome-online-accounts \
		libjson-glib-1.0.so:devel/json-glib \
		libexif.so:graphics/libexif \
		libpeas-1.0.so:devel/libpeas1 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libchamplain-0.12.so:graphics/libchamplain
RUN_DEPENDS=	eog:graphics/eog

PORTSCOUT=	limitw:1,even

USE_GNOME=	cairo gdkpixbuf gtk30 introspection libxml2
USES=		gettext gnome meson pkgconfig tar:xz

GLIB_SCHEMAS=	org.gnome.eog.plugins.exif-display.gschema.xml
NO_SHLIB_REQUIRES_GLOB=	libeog.so

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

PYTHON_MESON_ENABLE=python
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas1>=0:devel/py-libpeas1@${PY_FLAVOR}
PYTHON_USES=		python
PYTHON_VARS=		GLIB_SCHEMAS+="org.gnome.eog.plugins.export-to-folder.gschema.xml \
				       org.gnome.eog.plugins.fullscreenbg.gschema.xml \
				       org.gnome.eog.plugins.pythonconsole.gschema.xml"
PYTHON_BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
