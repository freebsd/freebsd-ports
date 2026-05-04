PORTNAME=	at-spi2-core
PORTVERSION=	2.60.3
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface
WWW=		https://gitlab.gnome.org/GNOME/at-spi2-core

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		dbus-testing gettext-tools gnome localbase meson python \
		pkgconfig shebangfix tar:xz
USE_GNOME=	glib20 introspection:build libxml2:build
USE_LDCONFIG=	yes
SHEBANG_FILES=	xml/generate-introspection.py
MESON_ARGS=	-Duse_systemd=false

TESTING_UNSAFE=	some tests fail on i386

BINARY_ALIAS=	python3=${PYTHON_CMD}

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		ATKONLY X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

ATKONLY_DESC=			Build only ATK (no atspi or at-spi2-atk, unsupported by upstream)
ATKONLY_LIB_DEPENDS_OFF=	libdbus-1.so:devel/dbus
ATKONLY_MESON_TRUE=		atk_only

X11_USES=		xorg
X11_USE=		XORG=x11,xi,xres,xtst
X11_MESON_ENABLED=	x11

.include <bsd.port.mk>
