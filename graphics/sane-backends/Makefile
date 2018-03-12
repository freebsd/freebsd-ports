# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-backends
PORTVERSION=	1.0.27
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/4146/ \
		http://fossies.org/linux/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2+

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		gmake jpeg libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} \
		--disable-latex \
		--disable-locking \
		--enable-pthread \
		--without-systemd
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_RC_SUBR=	saned
WRKSRC=		${WRKDIR}/${PORTNAME}-1.0.25

SUB_FILES=	pkg-message

USERS=	saned
GROUPS=	saned

PORTDOCS=	*

OPTIONS_DEFINE=		AVAHI DOCS GPHOTO IEEE1284 IPV6 NLS SNMP USB V4L
OPTIONS_DEFAULT=	USB
OPTIONS_SUB=		yes

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi
GPHOTO_LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2
GPHOTO_CONFIGURE_OFF=	--with-gphoto2=no
IEEE1284_DESC=		Parallel port support via libieee1284
IEEE1284_LIB_DEPENDS=	libieee1284.so:sysutils/libieee1284
IEEE1284_CONFIGURE_ENV_OFF=	sane_cv_use_libieee1284=no
IPV6_CONFIGURE_ENABLE=	ipv6
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	translations
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	snmp
USB_DESC=		USB support
USB_CONFIGURE_ON=	--enable-libusb_1_0
USB_CONFIGURE_OFF=	--enable-libusb=no
V4L_LIB_DEPENDS=	libv4l1.so:multimedia/libv4l
V4L_CONFIGURE_WITH=	v4l

post-patch:
	@${REINPLACE_CMD} -e '/for ac_header in/s|libc.h|sys/endian.h| ; \
		 s|"$${have_linux_ioctl_defines}"|"$${have_libv4l1}"|' \
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
