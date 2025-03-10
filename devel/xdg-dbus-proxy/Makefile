PORTNAME=	xdg-dbus-proxy
DISTVERSION=	0.1.6
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Filtering proxy for D-Bus connections
WWW=		https://github.com/flatpak/xdg-dbus-proxy

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	dbus-daemon:devel/dbus

USES=		gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20
GH_ACCOUNT=	flatpak
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MANPAGES_MESON_ENABLED=	man
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
