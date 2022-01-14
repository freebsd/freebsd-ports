# Created by: Rozhuk Ivan

PORTNAME=		libaravis
DISTVERSION=		0.8.20
CATEGORIES=		devel

PATCH_SITES=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=		cb27eb4e4c38553b6dfbbc70cc18caa51a365107.patch:-p1 # FreeBSD support

MAINTAINER=		rozhuk.im@gmail.com
COMMENT=		Camera control and image acquisition library

LICENSE=		LGPL21+
LICENSE_FILE=		${WRKSRC}/COPYING

USES=			gnome libtool meson pkgconfig
USE_GITHUB=		yes
GH_ACCOUNT=		AravisProject
GH_PROJECT=		aravis
USE_GNOME=		glib20 intltool libxml2
USE_LDCONFIG=		yes
INSTALL_TARGET=		install-strip

MESON_ARGS=		-Dpacket-socket=disabled -Dviewer=disabled	\
			-Dgst-plugin=disabled -Dtests=false

DOCSDIR=		${PREFIX}/share/gtk-doc/html/aravis-0.8

OPTIONS_DEFINE=		DOCS GIR NLS FAST_HEARTBEAT USB
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=		yes

DOCS_MESON_ENABLED=	documentation
DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

GIR_DESC=		Build Gobject Introspection
GIR_USE=		GNOME=introspection:build
GIR_MESON_ENABLED=	introspection

NLS_USES=		gettext

FAST_HEARTBEAT_DESC=	build with extremely fast heartbeat
FAST_HEARTBEAT_MESON_TRUE=	fast-heartbeat

USB_DESC=		build with USB support
USB_MESON_ENABLED=	usb

.include <bsd.port.mk>
