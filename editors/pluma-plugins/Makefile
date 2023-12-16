PORTNAME=	pluma-plugins
PORTVERSION=	1.26.0
PORTREVISION=	6
CATEGORIES=	editors mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for Pluma
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pluma>=0:editors/pluma \
		itstool:textproc/itstool \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
 		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgucharmap_2_90.so:deskutils/gucharmap
RUN_DEPENDS=	pluma>=0:editors/pluma \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase gmake pkgconfig \
		python shebangfix tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 gtksourceview4 intlhack introspection \
		intltool vte3
USE_CSTD=	c11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.pluma.plugins.sourcecodebrowser.gschema.xml \
		org.mate.pluma.plugins.terminal.gschema.xml \
		org.mate.pluma.plugins.wordcompletion.gschema.xml

.include <bsd.port.mk>
