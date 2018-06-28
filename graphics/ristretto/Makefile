# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ristretto
PORTVERSION=	0.8.3
CATEGORIES=	graphics xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Image viewer with Xfce integration

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		desktop-file-utils gettext-tools gmake pkgconfig tar:bzip2 xfce
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 intltool intlhack cairo
INSTALLS_ICONS=	yes
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=   nls

.include <bsd.port.mk>
