# New ports collection makefile for:	sane-backends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-backends
PORTVERSION=	1.0.17
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/download.php/1347/ \
		ftp://ftp.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp2.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp3.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/hci/sane/%SUBDIR%/ \
		http://gd.tuwien.ac.at/hci/sane/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

OPTIONS=	USB "USB support" on \
		NLS "NLS support" on \
		GPHOTO2 "gPhoto2 support" off

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} --disable-locking
MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if defined(WITHOUT_USB)
CONFIGURE_ARGS+=	--disable-libusb
.else
LIB_DEPENDS+=		usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-translations
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
PLIST_SUB+=		GPHOTO2=""
.else
CONFIGURE_ARGS+=	--with-gphoto2=no
PLIST_SUB+=		GPHOTO2="@comment "
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "*** ATTENTION ***"
	@${ECHO} ""
	@${ECHO} "Old versions then 1.0.17_1 do not check if you change config files."
	@${ECHO} "If it's your case, press CTRL+C and copy your config files."
	@${ECHO} ""

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|= \.\./libtool|= @LIBTOOL@|g'
	@${REINPLACE_CMD} -e 's|} -D_REENT|} ${PTHREAD_CFLAGS} -D_REENT|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
