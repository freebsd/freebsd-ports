# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-backends
PORTVERSION=	1.0.24
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3958/ \
		http://fossies.org/linux/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libv4l1.so:${PORTSDIR}/multimedia/libv4l

OPTIONS_DEFINE=	AVAHI CUPS DOCS GPHOTO IEEE1284 IPV6 NLS SNMP USB
OPTIONS_DEFAULT=	USB IPV6
OPTIONS_SUB=	yes
IEEE1284_DESC=	Pararell port support via libieee1284
USB_DESC=	USB support

USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} \
		--disable-latex \
		--disable-locking \
		--enable-pthread
USE_LDCONFIG=	yes

PORTDOCS=	*
USE_RC_SUBR=	saned
SUB_FILES+=	pkg-message

USERS=	saned
GROUPS=	saned

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app

CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client

GPHOTO_CONFIGURE_OFF=	--with-gphoto2=no
GPHOTO_LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2

IEEE1284_LIB_DEPENDS=	libieee1284.so:${PORTSDIR}/sysutils/libieee1284

IPV6_CONFIGURE_ENABLE=	ipv6

NLS_CONFIGURE_ENABLE=	translations
NLS_USES=		gettext

SNMP_CONFIGURE_WITH=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

USB_CONFIGURE_ENABLE=	libusb

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MCUPS}
CONFIGURE_ENV+=		ac_cv_header_cups_cups_h=no
.endif

.if ! ${PORT_OPTIONS:MIEEE1284}
CONFIGURE_ENV+=		sane_cv_use_libieee1284=no
.endif

post-extract:
	@((cd ${DISTDIR} && ${CAT} ${DISTFILES:C/:[^:]+$//}) | (cd ${WRKDIR} \
		&& ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} - ${EXTRACT_AFTER_ARGS}))

post-patch:
	@${REINPLACE_CMD} -e '/^for ac_header in/s|libc.h|cups/cups.h| ; \
		 s|-e .*/cups.h|"$$ac_cv_header_cups_cups_h" = "yes"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/s|COPYING||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|@libdir@|@prefix@/libdata|' \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} -e '/^export PKG_CONFIG_LIBDIR=/s|@libdir@|@prefix@/libdata|' \
		${WRKSRC}/tools/sane-config.in

.include <bsd.port.mk>
