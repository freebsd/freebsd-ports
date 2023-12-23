PORTNAME=	ristretto
PORTVERSION=	0.13.1
PORTREVISION=	3
CATEGORIES=	graphics xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Image viewer with Xfce integration
WWW=		https://goodies.xfce.org/projects/applications/ristretto

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libmenu xfconf
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		NLS TUMBLER
OPTIONS_DEFAULT=	TUMBLER
OPTIONS_SUB=		yes

TUMBLER_DESC=		Install Tumbler dependency for creating thumbnails

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

TUMBLER_RUN_DEPENDS=	xfce4-tumbler>0:deskutils/xfce4-tumbler

.include <bsd.port.mk>
