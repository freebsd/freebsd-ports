# New ports collection makefile for: 	gphoto
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gphoto
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.mustec.eu.org/~psj/downloads/ \
		http://www.freenix.no/~anders/

MAINTAINER=	anders@fix.no

BUILD_DEPENDS=	${LOCALBASE}/include/ppm.h:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_LIBTOOL=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${PREFIX}/bin/glib12-config" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		IMLIB_CONFIG="${X11BASE}/bin/imlib-config" \

MAN1=		gphoto.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/PROGRAMMERS ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/THANKS ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/THEMES ${PREFIX}/share/gphoto/doc
	@${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/gphoto/doc

.include <bsd.port.mk>
