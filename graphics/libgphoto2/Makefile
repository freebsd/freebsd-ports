# New ports collection makefile for: 	libgphoto2
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	libgphoto2
PORTVERSION=	2.1.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gphoto

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A universal digital camera picture control tool

LIB_DEPENDS=	usb-0.1.7:${PORTSDIR}/devel/libusb \
		exif.10:${PORTSDIR}/graphics/libexif

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnometarget pkgconfig
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes
PLIST_SUB=	VERSION=${PORTVERSION}

MAN3=		libgphoto2.3 libgphoto2_port.3

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
.for file in configure libgphoto2_port/configure
	@${REINPLACE_CMD} -e \
		's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g ; \
		 s|-g ||g' ${WRKSRC}/${file}
.endfor
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|po packaging doc|po doc|g ; \
		 s|: install-docDATA|:|g'

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
