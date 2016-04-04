# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-media
PORTVERSION=	1.12.1
CATEGORIES=	audio mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the MATE desktop

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libcanberra-gtk.so:audio/libcanberra \
		libmatemixer.so:audio/libmatemixer \
		libunique-1.0.so:x11-toolkits/unique

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_MATE=	desktop panel
USE_GNOME=	glib20 gtk20 intlhack libxml2
USE_LDCONFIG=	yes
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
