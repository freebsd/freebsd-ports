PORTNAME=	colobot
DISTVERSIONPREFIX=	${PORTNAME}-gold-
DISTVERSION=	0.2.0
PORTREVISION=	13
DISTVERSIONSUFFIX=	-alpha
CATEGORIES=	games education
MASTER_SITES=	https://colobot.info/files/music/:music
# music files are identical, keep old distfile for now
DISTFILES=	colobot-music_ogg_0.1.12-alpha.tar.gz:music

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Educational game aiming to teach programming to kids
WWW=		https://colobot.info/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/bin/xml:textproc/xmlstarlet
LIB_DEPENDS=	libpng.so:graphics/png \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libopenal.so:audio/openal-soft \
		libphysfs.so:devel/physfs \
		libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lang gettext-runtime gettext-tools:build \
		gl gnome localbase:ldflags openal perl5 python:build sdl \
		shebangfix
USE_GL=		gl glew glu
USE_GNOME=	librsvg2:build
USE_PERL5=	build
USE_SDL=	image2 ttf2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	colobot:colobot-data:0ac8197:data

LDFLAGS_i386=	-Wl,-znotext
SHEBANG_FILES=	data/i18n-tools/scripts/process_translations.py

BINARY_ALIAS=	xmlstarlet=${LOCALBASE}/bin/xml

post-extract:
	@${MV} ${WRKDIR}/colobot-data-0ac8197/* ${WRKSRC}/data
	@${MV} ${WRKDIR}/*.ogg ${WRKDIR}/LICENSE.txt ${WRKSRC}/data/music/

post-patch:
	${REINPLACE_CMD} '/COLOBOT_INSTALL_BIN_DIR/s|games|bin|' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} 's|PLATFORM_GNU|PLATFORM_GNU OR PLATFORM_FREEBSD|g' \
		${WRKSRC}/desktop/CMakeLists.txt
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/cmake/Find*.cmake \
		${WRKSRC}/tools/check-levels.sh
	${REINPLACE_CMD} 's|python|${PYTHON_CMD}|' ${WRKSRC}/data/tools/*.sh

.include <bsd.port.mk>
