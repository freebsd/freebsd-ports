PORTNAME=	blockattack
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Puzzle game inspired by Tetris

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip \
		${LOCALBASE}/include/utf8cpp/utf8.h:devel/utf8cpp
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libphysfs.so:devel/physfs

USES=		cmake compiler:c++11-lib gettext localbase:ldflags \
		pkgconfig sdl shebangfix
USE_GITHUB=	yes
USE_SDL=	image2 mixer2 ttf2
GH_PROJECT=	${PORTNAME}-game
SHEBANG_FILES=	packdata.sh source/misc/translation/*.sh
bash_CMD=	/bin/sh
CFLAGS+=	-I${LOCALBASE}/include/utf8cpp
LDFLAGS+=	-lintl

post-patch:
# Respect PREFIX when looking for data directories
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/source/code/sago/platform_folders.cpp

post-build:
# Generate game data and translations
	@(cd ${WRKSRC} && ${WRKSRC}/packdata.sh)

.include <bsd.port.mk>
