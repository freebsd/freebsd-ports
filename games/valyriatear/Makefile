PORTNAME=	valyriatear
PORTVERSION=	1.1.0
PORTREVISION=	8
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open Source J-RPG based on the Hero of Allacrost engine
WWW=		https://valyriatear.blogspot.com/

# Valyria Tear underwent a licensing audit.
# The main game is GPLv2 but artwork/music/fonts are a variety of licenses:
# GPLv2, GPLv3 (with font exception), OFL-1.1, CC0, CC-BY-3, and CC-BY-SA-3.
LICENSE=	GPLv2

BROKEN=		fails to build with boost-1.86+

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	Bertram25
GH_PROJECT=	ValyriaTear
GH_TUPLE=	ValyriaTear:luabind:76d4061:luabind/src/luabind \
		ValyriaTear:vt-utils:299411e:utils/src/utils

USES=		alias cmake compiler:c++11-lang gettext-tools gl gnome iconv \
		lua:51 openal sdl xorg
CMAKE_ARGS=	-DUSE_PCH_COMPILATION=OFF
USE_SDL=	sdl2 image2 ttf2
USE_GL=		gl glu glew
USE_XORG=	x11 xext sm ice
LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

#NLS_CMAKE_OFF=	-DDISABLE_TRANSLATIONS:BOOL=ON  # broken, so be happy with just not installing translation files
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/CMake/Modules/*.cmake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
