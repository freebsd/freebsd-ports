PORTNAME=	xwpe
DISTVERSION=	1.6.9
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/mendezr/xwpe/releases/download/v${DISTVERSION}/

MAINTAINER=	juan.mendezr@proton.me
COMMENT=	Borland-like IDE programming environment
WWW=		https://codeberg.org/mendezr/xwpe

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvterm.so:devel/libvterm \
		libjson-c.so:devel/json-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gmake gnome localbase ncurses pkgconfig xorg
USE_GNOME=	cairo pango
USE_XORG=	x11 xext xft
GNU_CONFIGURE=	yes
INFO=		xwpe

.include <bsd.port.mk>
