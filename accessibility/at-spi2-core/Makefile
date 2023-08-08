PORTNAME=	at-spi2-core
PORTVERSION=	2.48.0
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface
WWW=		https://gitlab.gnome.org/GNOME/at-spi2-core

LICENSE=	LGPL21

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ATKONLY X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

ATKONLY_DESC=	Build only ATK (no atspi or at-spi2-atk, unsupported by upstream)
ATKONLY_LIB_DEPENDS_OFF=	libdbus-1.so:devel/dbus
ATKONLY_MESON_TRUE= atk_only

X11_USES=		xorg
X11_USE=		XORG=x11,xi,xtst
X11_MESON_ENABLED=	x11

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
