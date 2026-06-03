PORTNAME=	melonds
PORTVERSION=	1.1
CATEGORIES=	games
PKGNAMESUFFIX=	-qt6

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Nintendo DS emulator
WWW=		https://melonds.kuribo64.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	static_assert failed due to requirement 'sizeof(TestCase) == 4312'

LIB_DEPENDS=	libfaad.so:audio/faad \
		libenet.so:net/enet \
		libslirp.so:net/libslirp

USES=		cmake compiler:c++17-lang desktop-file-utils gl gnome \
		iconv kde:6 libarchive pkgconfig qt:6 sdl xorg
USE_GL=		egl opengl
USE_GNOME=	glib20
USE_KDE=	ecm:build
USE_QT=		base multimedia
USE_SDL=	sdl2
USE_XORG=	ice sm x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	melonDS-emu
GH_PROJECT=	melonDS

CMAKE_ON=	USE_SYSTEM_LIBSLIRP

.include <bsd.port.mk>
