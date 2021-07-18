# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	caribou
PORTVERSION=	0.4.21
PORTREVISION=	3
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-glx-1.0.so:graphics/clutter \
		libgee-0.8.so:devel/libgee \
		libxklavier.so:x11/libxklavier \
		libcogl-path.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libatspi.so:accessibility/at-spi2-core \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atspi>=2.1.91:accessibility/py-atspi@${PY_FLAVOR}

USES=		gettext gl gmake gnome libtool localbase pathfix \
		pkgconfig python:3.3+ shebangfix tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack introspection:build libxml2 \
		libxslt:build pygobject3
USE_PYTHON=	py3kplist
SHEBANG_FILES=	tools/fix_gir.py tools/make_schema.py
USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr xtst
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-gtk2-module=no
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml \
		org.gnome.antler.gschema.xml

.include <bsd.port.mk>
