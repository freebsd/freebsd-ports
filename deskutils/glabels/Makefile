PORTNAME=	glabels
PORTVERSION=	3.4.1
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program to create labels and business cards
WWW=		http://snaught.com/glabels/

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup

USES=		desktop-file-utils gettext gmake gnome libtool pathfix \
		pkgconfig shared-mime-info tar:xz
USE_GNOME=	cairo gdkpixbuf gtk30 intltool librsvg2
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

GLIB_SCHEMAS=	org.gnome.glabels-3.gschema.xml

OPTIONS_DEFINE=	EVOLUTION
EVOLUTION_DESC=	Support evolution data server

EVOLUTION_USE=	GNOME=evolutiondataserver3
EVOLUTION_CONFIGURE_WITH=	libebook

.include <bsd.port.mk>
