# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$
#    $MCom: ports/graphics/gdk-pixbuf/Makefile,v 1.2 2006/09/10 00:51:10 mezz Exp $

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.22.0
PORTREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gdk-pixbuf/0.22
DISTNAME=	gdk-pixbuf-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USES=		gmake libtool pathfix tar:bzip2
USE_XORG=	xt xi x11
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${STAGEDIR}${PREFIX}/lib -L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} '/confexecdir =/s/=.*/= $$(sysconfdir)/' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
