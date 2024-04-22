PORTNAME=	nestopia
DISTVERSION=	1.52.1
CATEGORIES=	emulators

MAINTAINER=	mclay@astate.edu
COMMENT=	Portable NES/Famicom emulator
WWW=		http://0ldsk00l.ca/nestopia/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive \
		fltk>=0:x11-toolkits/fltk
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

USES=		autoreconf gl gnome jpeg libarchive \
		localbase:ldflags pkgconfig sdl
USE_CXXSTD=	c++98
USE_GITHUB=	yes
GH_ACCOUNT=	0ldsk00l
GNU_CONFIGURE=	yes
USE_GL=		gl glu
USE_SDL=	sdl2
USE_XORG=	xrender xcursor xfixes xext xft xinerama x11

OPTIONS_DEFINE=	DOCS JACK

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_WITH=	jack

.include <bsd.port.mk>
