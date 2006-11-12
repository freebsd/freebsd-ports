# New ports collection makefile for: 	libgphoto2
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	libgphoto2
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gphoto

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A universal digital camera picture control tool

LIB_DEPENDS=	usb:${PORTSDIR}/devel/libusb \
		exif:${PORTSDIR}/graphics/libexif

USE_BZIP2=	yes
USE_GNOME=	gnometarget pkgconfig ltverhack
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	configure libgphoto2_port/configure
INSTALLS_SHLIB=	yes
PLIST_SUB=	VERSION="${PORTVERSION}" VERSION_PORT=0.6.1

MAN3=		libgphoto2.3 libgphoto2_port.3

#LIBUSB_CFLAGS=	-I${LOCALBASE}/include
#LIBUSB_LIBS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
.for file in configure libgphoto2_port/configure
	@${REINPLACE_CMD} -e \
		's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g ; \
		 s|-g ||g' ${WRKSRC}/${file}
.endfor
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|: install-docDATA|:|g'
	@${REINPLACE_CMD} -e 's|linux-hotplug ||' ${WRKSRC}/packaging/Makefile.in

pre-build:
	@cd ${WRKSRC} && ${GMAKE} all-local

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${PREFIX}/share/doc/libgphoto2_port
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/libgphoto2_port/${file} \
		${PREFIX}/share/doc/libgphoto2_port
.endfor
.endif

.include <bsd.port.mk>
