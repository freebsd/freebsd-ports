PORTNAME=	blockattack
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Puzzle game inspired by Tetris
WWW=		https://blockattack.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		zip:archivers/zip
LIB_DEPENDS=	libphysfs.so:devel/physfs

USES=		cmake compiler:c++11-lib gettext-tools localbase:ldflags \
		pkgconfig sdl shebangfix
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-game
USE_SDL=	image2 mixer2 ttf2
SHEBANG_FILES=	packdata.sh source/misc/translation/*.sh
bash_CMD=	${SH}
CMAKE_ON=	Boost_USE_STATIC_LIBS
LDFLAGS+=	-lintl

post-patch:
# Drop dependency on bash/zsh features: directory stacking
	@${REINPLACE_CMD} -e 's/pushd/cd/; s/popd/cd -/' \
		${WRKSRC}/packdata.sh
# Respect PREFIX when looking for data directories
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/source/misc/embedded_libs/PlatformFolders-*/sago/platform_folders.cpp

post-build:
# Generate game data and translations
	@(cd ${WRKSRC} && \
		${WRKSRC}/packdata.sh)

.include <bsd.port.mk>
