# New ports collection makefile for:	libexif-gtk
# Date created:		10 Jun 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libexif-gtk
PORTVERSION=	0.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libexif

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		exif.5:${PORTSDIR}/graphics/libexif
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GTK=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\$$\(libdir\)/pkgconfig|\$$\(prefix\)/libdata/pkgconfig|g'

.include <bsd.port.mk>
