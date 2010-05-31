# New ports collection makefile for:	sane-backends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-backends
PORTVERSION=	1.0.21
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3258/ \
		ftp://ftp.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp2.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp3.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/hci/sane/%SUBDIR%/ \
		http://gd.tuwien.ac.at/hci/sane/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

OPTIONS=	USB "USB support" on \
		NLS "NLS support" on \
		GPHOTO2 "gPhoto2 support" off \
		AVAHI "Avahi support" off \
		IEEE1284 "libieee1284 support" off \
		IPV6 "IPV6 support" off

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} \
		--disable-latex \
		--disable-locking
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

USE_RC_SUBR=	saned
SUB_FILES+=	pkg-install pkg-message

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if defined(WITHOUT_USB)
CONFIGURE_ARGS+=	--disable-libusb
.else
.if ${OSVERSION} < 800069
LIB_DEPENDS+=		usb-0.1.8:${PORTSDIR}/devel/libusb
.endif
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-translations
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
MAN5+=			sane-gphoto2.5
PLIST_SUB+=		GPHOTO2=""
.else
CONFIGURE_ARGS+=	--with-gphoto2=no
PLIST_SUB+=		GPHOTO2="@comment "
.endif

.if defined(WITH_AVAHI)
LIB_DEPENDS+=		avahi-client.3:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--enable-avahi
.endif

.if defined(WITH_IEEE1284)
LIB_DEPENDS+=		ieee1284.5:${PORTSDIR}/sysutils/libieee1284
PLIST_SUB+=		IEEE1284=""
.else
CONFIGURE_ENV+=		sane_cv_use_libieee1284=no
PLIST_SUB+=		IEEE1284="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^for ac_header in/s|libc.h||g ; \
		 s|} -D_REENT|} ${PTHREAD_CFLAGS} -D_REENT|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@(cd ${WRKSRC}/po; ${BASENAME} -s .po `${LS} *.po` > LINGUAS)

# Pass BATCH to pkg-install for Evil Things(tm)
pre-install:
	@BATCH="${BATCH}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
