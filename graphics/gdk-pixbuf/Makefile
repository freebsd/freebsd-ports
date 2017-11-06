# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#    $MCom: ports/graphics/gdk-pixbuf/Makefile,v 1.2 2006/09/10 00:51:10 mezz Exp $

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.22.0
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DISTNAME=	gdk-pixbuf-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

PORTSCOUT=	ignore:1

USES=		cpe gmake jpeg libtool localbase pathfix tar:bzip2
CPE_VENDOR=	gnome
USE_XORG=	xt xi x11
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc

post-patch:
	@${REINPLACE_CMD} '/confexecdir =/s/=.*/= $$(sysconfdir)/' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
