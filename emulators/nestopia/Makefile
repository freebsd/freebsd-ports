PORTNAME=	nestopia
DISTVERSION=	1.51.0
CATEGORIES=	emulators

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Portable NES/Famicom emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libao.so:audio/libao \
		libepoxy.so:graphics/libepoxy \
		libfltk.so:x11-toolkits/fltk

USES=		autoreconf desktop-file-utils gl libarchive localbase:ldflags \
		pkgconfig sdl
USE_CXXSTD=	c++98
USE_GITHUB=	yes
GH_ACCOUNT=	rdanbrook
GNU_CONFIGURE=	yes
USE_GL=		glu
USE_SDL=	sdl2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS JACK

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_WITH=	jack

.include <bsd.port.mk>
