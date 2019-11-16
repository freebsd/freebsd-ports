# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-backends
PORTVERSION=	1.0.28
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.com/sane-project/backends/uploads/9e718daff347826f4cfe21126c8d5091/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		gmake jpeg libtool localbase pathfix pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-locking \
		--enable-pthread \
		--without-api-spec \
		--without-systemd
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_RC_SUBR=	saned

SUB_FILES=	pkg-message

USERS=		saned
GROUPS=		saned

OPTIONS_DEFINE=		AVAHI DOCS GPHOTO IEEE1284 IPV6 NLS SNMP USB V4L
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=		yes

IEEE1284_DESC=		Parallel port support via libieee1284
USB_DESC=		USB support

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi
GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_CONFIGURE_OFF=	--with-gphoto2=no
IEEE1284_LIB_DEPENDS=	libieee1284.so:sysutils/libieee1284
IEEE1284_CONFIGURE_ENV_OFF=	sane_cv_use_libieee1284=no
IPV6_CONFIGURE_ENABLE=	ipv6
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	snmp
USB_CONFIGURE_ON=	--with-usb
USB_CONFIGURE_OFF=	--with-usb=no
V4L_LIB_DEPENDS=	libv4l1.so:multimedia/libv4l
V4L_CONFIGURE_WITH=	v4l

post-patch:
	@${REINPLACE_CMD} -e '/for ac_header in/s|libc.h|sys/endian.h| ; \
		 s|"$${have_linux_ioctl_defines}"|"$${have_libv4l1}"| ; \
		 /pthread_t[[:space:]]k;[[:space:]]/s|pthread_t[[:space:]]k;[[:space:]]k[[:space:]]\*[[:space:]]1|pthread_t k; k = (pthread_t) -1|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/s|COPYING||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|HAVE_LIBC_H|HAVE_SYS_ENDIAN_H|' \
		${WRKSRC}/include/sane/config.h.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|@libdir@|@prefix@/libdata|' \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} -e '/^export PKG_CONFIG_LIBDIR=/s|@libdir@|@prefix@/libdata|' \
		${WRKSRC}/tools/sane-config.in

.include <bsd.port.mk>
