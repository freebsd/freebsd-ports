# Created by: Rozhuk Ivan
# $FreeBSD$

PORTNAME=		libaravis
DISTVERSIONPREFIX=	ARAVIS_
DISTVERSION=		0_5_11
CATEGORIES=		devel

MAINTAINER=		rozhuk.im@gmail.com
COMMENT=		Camera control and image acquisition library

LICENSE=		LGPL21+
LICENSE_FILE=		${WRKSRC}/COPYING

BUILD_DEPENDS=		g-ir-compiler:devel/gobject-introspection

CONFLICTS_INSTALL=	${PORTNAME}*

USES=			pkgconfig autoreconf libtool gmake
GNU_CONFIGURE=		yes
USE_GITHUB=		yes
GH_ACCOUNT=		AravisProject
GH_PROJECT=		aravis
USE_GNOME=		glib20 intltool libxml2
USE_LDCONFIG=		yes
INSTALL_TARGET=		install-strip

CONFIGURE_ARGS=		--enable-packet-socket=no --enable-viewer=no	\
			--enable-gst-plugin=no --enable-gst-0.10-plugin=no \
			--enable-cpp-test=no --enable-zlib-pc=yes
MAKE_ARGS=		pkgconfigdir="${PREFIX}/libdata/pkgconfig"

DOCSDIR=		${PREFIX}/share/doc/aravis/aravis-0.6

OPTIONS_DEFINE=		DOCS NLS FAST_HEARTBEAT USB
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=		yes

NLS_USES=		gettext

FAST_HEARTBEAT_DESC=	build with extremely fast heartbeat
FAST_HEARTBEAT_CONFIGURE_ENABLE=	fast-heartbeat

USB_DESC=		build with USB support
USB_CONFIGURE_ENABLE=	usb

pre-configure:
	@${ECHO_CMD} "EXTRA_DIST =" >> ${WRKSRC}/gtk-doc.make

.include <bsd.port.mk>
