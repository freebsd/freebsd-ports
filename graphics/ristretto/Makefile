PORTNAME=	ristretto
PORTVERSION=	0.13.4
CATEGORIES=	graphics xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Image viewer with Xfce integration
WWW=		https://docs.xfce.org/apps/ristretto/start

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexif.so:graphics/libexif

USES=		cmake:indirect compiler:c11 desktop-file-utils gettext-tools gnome \
		meson pkgconfig tar:xz xfce xorg
USE_GNOME=	cairo gdkpixbuf glib20 gtk30
USE_XFCE=	libexo libmenu xfconf
USE_XORG=	ice sm x11

OPTIONS_DEFINE=		NLS TUMBLER
OPTIONS_DEFAULT=	TUMBLER
OPTIONS_SUB=		yes

TUMBLER_DESC=		Install Tumbler dependency for creating thumbnails

NLS_USES=		gettext-runtime

TUMBLER_RUN_DEPENDS=	xfce4-tumbler>0:deskutils/xfce4-tumbler

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
