# $FreeBSD$

PORTNAME=	nestopia
DISTVERSION=	1.50
CATEGORIES=	emulators

MAINTAINER=	neel@neelc.org
COMMENT=	Portable NES/Famicom emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libao.so:audio/libao libepoxy.so:graphics/libepoxy

USES=		autoreconf desktop-file-utils gl gnome libarchive \
		localbase:ldflags pkgconfig sdl
USE_CXXSTD=	c++98
USE_GITHUB=	yes
GH_ACCOUNT=	rdanbrook
GNU_CONFIGURE=	yes
USE_GL=		glu
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_SDL=	sdl2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS JACK

JACK_LIB_DEPENDS=libjack.so:audio/jack
JACK_CONFIGURE_WITH=jack

.include <bsd.port.mk>
