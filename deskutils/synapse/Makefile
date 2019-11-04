# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	synapse
DISTVERSION=	0.2.99.4
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/363823069/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Semantic application launcher written in Vala

LICENSE=	GPLv2 LGPL21 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPL2
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL2.1
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist \
		libgee-0.8.so:devel/libgee \
		libjson-glib-1.0.so:devel/json-glib \
		libkeybinder-3.0.so:x11/keybinder-gtk3 \
		libnotify.so:devel/libnotify \
		librest-0.7.so:devel/librest \
		libsoup-2.4.so:devel/libsoup

USES=		gettext-tools gmake gnome pkgconfig tar:xz xorg
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
USE_XORG=	x11
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
