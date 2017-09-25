# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	valyriatear
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open Source J-RPG based on the Hero of Allacrost engine

# Valyria Tear underwent a licensing audit.
# The main game is GPLv2 but artwork/music/fonts are a variety of licenses:
# GPLv2, GPLv3 (with font exception), OFL-1.1, CC0, CC-BY-3, and CC-BY-SA-3.
LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	Bertram25
GH_PROJECT=	ValyriaTear
GH_TAGNAME=	${PORTVERSION}-gcc5 # contains relevant tolua++ fixes

USES=		alias cmake gettext-tools iconv lua:51 openal
CMAKE_ARGS=	-DUSE_PCH_COMPILATION=OFF
USE_SDL=	sdl image ttf
USE_GL=		gl glu
USE_XORG=	x11 xext sm ice
INSTALLS_ICONS=	yes

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	EDITOR DOCS NLS
OPTIONS_SUB=	yes

EDITOR_DESC=	Compile the Qt editor along with the game
EDITOR_CMAKE_BOOL=	EDITOR_SUPPORT
EDITOR_USE=	QT4=corelib,gui,opengl,qmake_build,moc_build,uic_build,rcc_build
EDITOR_DESKTOP_ENTRIES=	\
		"Valyria Tear Editor" \
		"Map editor for Valyria Tear game" \
		"valyriatear" \
		"vt-editor" \
		"Graphics;2DGraphics;" \
		""

NLS_CMAKE_OFF=	-DDISABLE_TRANSLATIONS:BOOL=OFF
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/CMake/Modules/*.cmake

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
