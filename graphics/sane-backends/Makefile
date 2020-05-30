# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-backends
PORTVERSION=	1.0.30
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.com/sane-project/backends/uploads/c3dd60c9e054b5dee1e7b01a7edc98b0/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang gmake gnome jpeg libtool localbase pathfix \
		pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	saned

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-locking \
		--enable-pthread \
		--without-api-spec \
		--without-systemd
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

USERS=		saned
GROUPS=		saned

PLIST_SUB=	SOVERSION=${PORTVERSION}

OPTIONS_DEFINE=		AVAHI DOCS GPHOTO IEEE1284 IPV6 NLS SNMP USB V4L
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=		yes

IEEE1284_DESC=	Parallel port support via libieee1284
USB_DESC=	USB support

AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app \
				libcurl.so:ftp/curl
AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_CONFIGURE_WITH=		libcurl
GPHOTO_LIB_DEPENDS=		libgphoto2.so:graphics/libgphoto2
GPHOTO_CONFIGURE_OFF=		--with-gphoto2=no
IEEE1284_LIB_DEPENDS=		libieee1284.so:sysutils/libieee1284
IEEE1284_CONFIGURE_ENV_OFF=	sane_cv_use_libieee1284=no
IPV6_CONFIGURE_ENABLE=		ipv6
NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls
SNMP_LIB_DEPENDS=		libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=		snmp
USB_CONFIGURE_OFF=		--with-usb=no
USB_CONFIGURE_ON=		--with-usb
V4L_LIB_DEPENDS=		libv4l1.so:multimedia/libv4l
V4L_CONFIGURE_WITH=		v4l

.include <bsd.port.mk>
