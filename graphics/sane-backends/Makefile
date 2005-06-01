# New ports collection makefile for:	sane-backends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-backends
PORTVERSION=	1.0.15
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp2.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp3.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/hci/sane/%SUBDIR%/ \
		http://gd.tuwien.ac.at/hci/sane/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gnometarget lthack
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS} \
		DOCSDIR="${DOCSDIR}"
INSTALLS_SHLIB=	yes

OPTIONS=	USB "USB support" on \
		NLS "NLS support" on \
		GPHOTO2 "gPhoto2 support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_USB)
CONFIGURE_ARGS+=	--disable-libusb
PLIST_SUB+=	USB="@comment "
.else
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
PLIST_SUB+=	USB=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-translations
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
PLIST_SUB+=	GPHOTO2=""
.else
CONFIGURE_ARGS+=	--with-gphoto2=no
PLIST_SUB+=	GPHOTO2="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|LIBTOOL =.*|LIBTOOL = ${LIBTOOL}|' \
		${WRKSRC}/backend/Makefile.in ${WRKSRC}/frontend/Makefile.in \
		${WRKSRC}/japi/Makefile.in ${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/sanei/Makefile.in ${WRKSRC}/tools/Makefile.in

.include "Makefile.man"
.include <bsd.port.post.mk>
