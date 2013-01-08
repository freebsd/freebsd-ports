# Created by: gary@hotlava.com
# $FreeBSD$

PORTNAME=	sane-backends
PORTVERSION=	1.0.23
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3752/:3752 \
		http://alioth.debian.org/frs/download.php/3753/:3753 \
		http://alioth.debian.org/frs/download.php/3754/:3754 \
		ftp://ftp2.sane-project.org/pub/sane/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}.1:3752,DEFAULT \
		${DISTNAME}${EXTRACT_SUFX}.2:3753,DEFAULT \
		${DISTNAME}${EXTRACT_SUFX}.3:3754,DEFAULT
EXTRACT_ONLY=	# need to concatenate before extraction

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

OPTIONS_DEFINE=	USB GPHOTO2 SNMP AVAHI IEEE1284 IPV6 DOCS
OPTIONS_DEFAULT=	USB

USB_DESC=	USB support
GPHOTO2_DESC=	gPhoto2 support
IEEE1284_DESC=	libieee1284 support

USE_GNOME=	gnomehack
USE_PKGCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${WRKDIR}/tmproot \
		--disable-latex \
		--disable-locking \
		--enable-pthread
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

USE_RC_SUBR=	saned
SUB_FILES+=	pkg-message

USERS=	saned
GROUPS=	saned

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUSB}
.if ${OSVERSION} < 800069
LIB_DEPENDS+=		usb-0.1:${PORTSDIR}/devel/libusb
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
LIB_DEPENDS+=		gphoto2:${PORTSDIR}/graphics/libgphoto2
MAN5+=			sane-gphoto2.5
PLIST_SUB+=		GPHOTO2=""
.else
CONFIGURE_ARGS+=	--with-gphoto2=no
PLIST_SUB+=		GPHOTO2="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=		netsnmp:${PORTSDIR}/net-mgmt/net-snmp
.else
CONFIGURE_ARGS+=	--without-snmp
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=		avahi-client:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--enable-avahi
.endif

.if ${PORT_OPTIONS:MIEEE1284}
LIB_DEPENDS+=		ieee1284:${PORTSDIR}/sysutils/libieee1284
PLIST_SUB+=		IEEE1284=""
MAN5+=			sane-canon_pp.5 sane-hpsj5s.5 sane-mustek_pp.5
.else
CONFIGURE_ENV+=		sane_cv_use_libieee1284=no
PLIST_SUB+=		IEEE1284="@comment "
.endif

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=		cups:${PORTSDIR}/print/cups-client
.else
CONFIGURE_ENV+=		ac_cv_header_cups_cups_h=no
.endif

post-extract:
	@((cd ${DISTDIR} && ${CAT} ${DISTFILES:C/:[^:]+$//}) | (cd ${WRKDIR} \
		&& ${EXTRACT_CMD} ${EXTRACT_BEFOR_ARGS} ${EXTRACT_AFTER_ARGS}))

post-patch:
	@${REINPLACE_CMD} -e '/^for ac_header in/s|libc.h|cups/cups.h| ; \
		 s|-e .*/cups.h|"$$ac_cv_header_cups_cups_h" = "yes"| ; \
		 s|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^dist_doc_DATA/s|COPYING||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|@libdir@|@prefix@/libdata|' \
		${WRKSRC}/tools/Makefile.in
	@${REINPLACE_CMD} -e '/^export PKG_CONFIG_LIBDIR=/s|@libdir@|@prefix@/libdata|' \
		${WRKSRC}/tools/sane-config.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKDIR}/tmproot && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
