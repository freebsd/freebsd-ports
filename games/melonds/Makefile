PORTNAME=	melonds
PORTVERSION=	0.9.5
CATEGORIES=	games
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Nintendo DS emulator
WWW=		https://melonds.kuribo64.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	static_assert failed due to requirement 'sizeof(TestCase) == 4312'

LIB_DEPENDS=	libslirp.so:net/libslirp

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++17-lang desktop-file-utils gnome \
		iconv libarchive pkgconfig qt:${FLAVOR:S/qt//} sdl kde:5
USE_GNOME=	glib20
USE_SDL=	sdl2
USE_KDE=	ecm:build

.if ${FLAVOR} == qt5
CMAKE_OFF=	USE_QT6
.else
CMAKE_ON=	USE_QT6
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	melonDS-emu
GH_PROJECT=	melonDS
GH_TAGNAME=	0.9.5

qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-qt5

_USE_QT5=	core gui network widgets multimedia buildtools:build qmake:build
_USE_QT6=	base multimedia
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}

.include <bsd.port.mk>
