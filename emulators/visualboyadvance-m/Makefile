PORTNAME=	visualboyadvance-m
DISTVERSIONPREFIX=v
DISTVERSION=	2.2.3
CATEGORIES=	emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game Boy Advance emulator with GTK frontend
WWW=		https://vba-m.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/gpl.txt

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libatk-1.0.so:accessibility/at-spi2-core \
		libharfbuzz.so:print/harfbuzz \
		libwayland-client.so:graphics/wayland

USES=		cmake gl gettext-runtime gettext-tools gnome iconv pkgconfig \
		sdl xorg

USE_GITHUB=	yes
USE_GL=		gl glu
USE_GNOME=	cairo glib20 gtk30 gdkpixbuf pango
USE_SDL=	sdl2
USE_WX=		3.2+
USE_XORG=	x11 xext xscrnsaver

.include <bsd.port.mk>
