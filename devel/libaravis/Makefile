PORTNAME=	libaravis
DISTVERSION=	0.8.34
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Camera control and image acquisition library
WWW=		https://github.com/AravisProject/aravis/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	AravisProject
GH_PROJECT=	aravis
USE_GNOME=	glib20 intltool introspection:build libxml2
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgst-plugin=disabled \
		-Dintrospection=enabled \
		-Dpacket-socket=disabled \
		-Dtests=false \
		-Dviewer=disabled

INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/aravis-0.8

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		DOCS FAST_HEARTBEAT NLS USB
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=		yes

FAST_HEARTBEAT_DESC=	build with extremely fast heartbeat
USB_DESC=		build with USB support

DOCS_BUILD_DEPENDS=		gi-docgen:textproc/py-gi-docgen
DOCS_MESON_ENABLED=		documentation
FAST_HEARTBEAT_MESON_TRUE=	fast-heartbeat
NLS_USES=			gettext
USB_MESON_ENABLED=		usb

.include <bsd.port.mk>
