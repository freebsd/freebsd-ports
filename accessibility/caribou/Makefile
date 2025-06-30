PORTNAME=	caribou
DISTVERSION=	0.4.21-78
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g9c900f0
CATEGORIES=	accessibility gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard
WWW=		https://live.gnome.org/Caribou

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libclutter-glx-1.0.so:graphics/clutter \
		libgee-0.8.so:devel/libgee \
		libxklavier.so:x11/libxklavier \
		libcogl-path.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libatspi.so:accessibility/at-spi2-core \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atspi>=2.1.91:accessibility/py-atspi@${PY_FLAVOR}

USES=		autoreconf:2.69 gettext gl gmake gnome libtool localbase pathfix \
		pkgconfig python shebangfix vala:build xorg

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org/
GL_ACCOUNT=	Archive

USE_GNOME=	cairo gdkpixbuf gtk30 intlhack introspection:build libxml2 \
		libxslt:build pygobject3
GLIB_SCHEMAS=	org.gnome.caribou.gschema.xml \
		org.gnome.antler.gschema.xml

SHEBANG_GLOB=	*.py*

USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr xtst

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk2-module
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
