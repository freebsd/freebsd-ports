# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-screenshot
PORTVERSION=	3.22.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 utility for making picutures of your screen

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra

CONFLICTS=	gnome-utils-2.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		gettext-tools gmake gnome localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.gnome-screenshot.gschema.xml

OPTIONS_DEFINE=	INTEL_FIX NLS
OPTIONS_SUB=	yes

# Workaround garbled screenshot when 3D hardware acceleration is enabled
# via x11-drivers/xf86-video-intel port
INTEL_FIX_DESC=		Don't try to use the gnome-shell interface
INTEL_FIX_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-intel

NLS_USES=		gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
