PORTNAME=	pluma-plugins
DISTVERSION=	1.28.0
PORTREVISION=	6
CATEGORIES=	editors mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for Pluma
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pluma>=0:editors/pluma \
		itstool:textproc/itstool \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpeas1>=0:devel/py-libpeas1@${PY_FLAVOR}
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas1 \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgucharmap_2_90.so:deskutils/gucharmap
RUN_DEPENDS=	pluma>=0:editors/pluma \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpeas1>=0:devel/py-libpeas1@${PY_FLAVOR}

USES=		compiler:c11 gettext gnome libtool:keepla localbase gmake \
		pkgconfig python shebangfix tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_GNOME=	cairo gdkpixbuf gtk30 gtksourceview4 intlhack introspection \
		intltool vte3
USE_CSTD=	c11
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

GLIB_SCHEMAS=	org.mate.pluma.plugins.sourcecodebrowser.gschema.xml \
		org.mate.pluma.plugins.terminal.gschema.xml \
		org.mate.pluma.plugins.wordcompletion.gschema.xml

.include <bsd.port.mk>
