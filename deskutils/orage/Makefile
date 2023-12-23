PORTNAME=	orage
PORTVERSION=	4.18.0
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Calendar application for the Xfce Desktop
WWW=		https://git.xfce.org/apps/orage/about/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libical.so:devel/libical \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang desktop-file-utils gettext gmake gnome \
		libtool pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libmenu
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=libnotify

.include <bsd.port.mk>
