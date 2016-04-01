# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	wxlauncher
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	release-
CATEGORIES=	games

MAINTAINER=	lightside@gmx.com
COMMENT=	Multi-platform launcher for the Freespace 2 Source Code Project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPLv2.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	scp-fs2open
GH_PROJECT=	wxLauncher

USES=		cmake:outsource openal pkgconfig python:2,build
USE_SDL=	sdl2
CMAKE_ARGS+=	-DRESOURCES_PATH:STRING="${DATADIR}"

PORTDATA=	*
PORTDOCS=	Authors.md License.txt ReadMe*.md Thanks.txt

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="wxLauncher" "${COMMENT}" \
		"${PORTNAME}" "${PORTNAME}" \
		"Game;" false

OPTIONS_DEFINE=	DEBUG DOCS JOYSTICK WX3
OPTIONS_DEFAULT=	JOYSTICK WX3
DEBUG_CXXFLAGS_OFF=	-DNDEBUG
JOYSTICK_DESC=	Build with joystick support
JOYSTICK_CMAKE_ON=	-DUSE_JOYSTICK:BOOL=ON
JOYSTICK_CMAKE_OFF=	-DUSE_JOYSTICK:BOOL=OFF
WX3_DESC=	Build with using wxWidgets 3.0+ version (2.8 otherwise)
WX3_CXXFLAGS=	-std=c++11
WX3_USES=	compiler:c++11-lib
WX3_USE=	WX=3.0+
WX3_USE_OFF=	WX=2.8
WX3_CMAKE_ON=	-DWXVER:STRING="3.0"
WX3_CMAKE_OFF=	-DWXVER:STRING="2.8"

post-patch: .SILENT
# Change version_strings.cpp.in file, based on GH_TAGNAME, without using git
	${REINPLACE_CMD} -e '/find_program(GIT_EXECUTABLE/d ; \
		/version_strings.cpp will be generated/d' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|123456789abc+ unknown custom tip|${GH_TAGNAME}|' \
		${WRKSRC}/code/global/version_strings.cpp.in

pre-install:
	${INSTALL_DATA} ${WRKSRC}/onlinehelp/images/header.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
