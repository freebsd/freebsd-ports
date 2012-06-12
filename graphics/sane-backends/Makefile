# New ports collection makefile for:	sane-backends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-backends
PORTVERSION=	1.0.22
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3503/ \
		ftp://ftp2.sane-project.org/pub/sane/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

OPTIONS_DEFINE=	USB NLS GPHOTO2 SNMP AVAHI IEEE1284 IPV6 DOCS
OPTIONS_DEFAULT=	USB

USB_DESC=	USB support
GPHOTO2_DESC=	gPhoto2 support
IEEE1284_DESC=	libieee1284 support

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} \
		--disable-latex \
		--disable-locking \
		--enable-pthread
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	saned
SUB_FILES+=	pkg-message

USERS=	saned
GROUPS=	saned

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
MAKE_ENV+=	NOPORTDOCS=1
.endif

.if ${PORT_OPTIONS:MUSB}
.if ${OSVERSION} < 800069
LIB_DEPENDS+=		usb-0.1.8:${PORTSDIR}/devel/libusb
.endif
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-translations
PLIST_SUB+=		NLS="@comment "
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MGPHOTO2}
LIB_DEPENDS+=		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
MAN5+=			sane-gphoto2.5
PLIST_SUB+=		GPHOTO2=""
.else
CONFIGURE_ARGS+=	--with-gphoto2=no
PLIST_SUB+=		GPHOTO2="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=		netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp
.else
CONFIGURE_ARGS+=	--without-snmp
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=		avahi-client.3:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--enable-avahi
.endif

.if ${PORT_OPTIONS:MIEEE1284}
LIB_DEPENDS+=		ieee1284.5:${PORTSDIR}/sysutils/libieee1284
PLIST_SUB+=		IEEE1284=""
.else
CONFIGURE_ENV+=		sane_cv_use_libieee1284=no
PLIST_SUB+=		IEEE1284="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^for ac_header in/s|libc.h||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
