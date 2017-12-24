# Created by: Rozhuk Ivan
# $FreeBSD$

PORTNAME=		libaravis
PORTVERSION=		0.5.9
CATEGORIES=		devel

MAINTAINER=		rozhuk.im@gmail.com
COMMENT=		Camera control and image acquisition library

LICENSE=		LGPL21+

USE_GITHUB=		yes
GH_ACCOUNT=		AravisProject
GH_PROJECT=		aravis
GH_TAGNAME=		c681c52

CONFLICTS_INSTALL=	${PORTNAME}*
DOCSDIR=		${PREFIX}/share/doc/aravis/aravis-0.6

USE_GNOME=		glib20 intltool
LIB_DEPENDS+=		libxml2.so:textproc/libxml2 \
			libgirepository-1.0.so:devel/gobject-introspection

USES=			pkgconfig autoreconf libtool gmake
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
MAKE_ARGS=		pkgconfigdir="${PREFIX}/libdata/pkgconfig"

OPTIONS_DEFINE=		DOCS NLS FAST_HEARTBEAT USB
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=		yes

CONFIGURE_ARGS=		--enable-packet-socket=no --enable-viewer=no	\
			--enable-gst-plugin=no --enable-gst-0.10-plugin=no \
			--enable-cpp-test=no --enable-zlib-pc=yes

NLS_USES=		gettext

FAST_HEARTBEAT_DESC=	build with extremely fast heartbeat
FAST_HEARTBEAT_CONFIGURE_ENABLE=	fast-heartbeat

USB_DESC=		build with USB support
USB_CONFIGURE_ENABLE=	usb

pre-configure:
	${ECHO_CMD} "EXTRA_DIST =" >> ${WRKSRC}/gtk-doc.make
	@${REINPLACE_CMD} -e 's|GTK_DOC_CHECK(\[1.14\],\[--flavour no-tmpl\])||' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|SUBDIRS += tests po docs|SUBDIRS += po docs|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
