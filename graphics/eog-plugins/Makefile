# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eog-plugins
PORTVERSION=	3.26.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plug-ins for the Eye of GNOME image viewer application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	eog:graphics/eog
LIB_DEPENDS=	libgdata.so:devel/libgdata \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libexif.so:graphics/libexif \
		libpeas-1.0.so:devel/libpeas \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	eog:graphics/eog

PORTSCOUT=	limitw:1,even

USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection libxml2
USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.eog.plugins.exif-display.gschema.xml

OPTIONS_DEFINE=	CHAMPLAIN PYTHON
OPTIONS_DEFAULT=CHAMPLAIN PYTHON
OPTIONS_SUB=	yes
CHAMPLAIN_DESC=	Champlain map plugin

CHAMPLAIN_LIB_DEPENDS=	libcogl.so:graphics/cogl \
			libclutter-1.0.so:graphics/clutter \
			libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
			libchamplain-0.12.so:graphics/libchamplain
CHAMPLAIN_USES=		gl xorg
CHAMPLAIN_USE=		GL=egl XORG=x11,xcomposite,xdamage,xext,xfixes,xi,xrandr

PYTHON_CONFIGURE_ENABLE=python
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}
PYTHON_USES=		python:3.4+
PYTHON_VARS=		GLIB_SCHEMAS+="org.gnome.eog.plugins.export-to-folder.gschema.xml \
				       org.gnome.eog.plugins.fullscreenbg.gschema.xml \
				       org.gnome.eog.plugins.pythonconsole.gschema.xml"

post-patch-CHAMPLAIN-off:
	@${REINPLACE_CMD} -e 's|champlain-gtk|disabled-champlain-gtk|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^DEFAULT_PLUGINS=/,/^$$/ s/map//' \
		${WRKSRC}/configure

.include <bsd.port.mk>
