PORTNAME=	blockattack
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Puzzle game inspired by Tetris

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip \
		boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libphysfs.so:devel/physfs

USES=		cmake compiler:c++11-lib gettext localbase:ldflags \
		pkgconfig sdl shebangfix
USE_GITHUB=	yes
USE_SDL=	image2 mixer2 ttf2
GH_PROJECT=	${PORTNAME}-game
SHEBANG_FILES=	packdata.sh source/misc/translation/*.sh
bash_CMD=	/bin/sh
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
	@(cd ${WRKSRC} && ${WRKSRC}/packdata.sh)

.include <bsd.port.mk>
