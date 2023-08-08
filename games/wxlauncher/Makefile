PORTNAME=	wxlauncher
PORTVERSION=	0.10.1
DISTVERSIONPREFIX=	release-
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-platform launcher for the Freespace 2 Source Code Project
WWW=		https://github.com/scp-fs2open/wxLauncher

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPLv2.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cmake openal pkgconfig python:build sdl
USE_GITHUB=	yes
GH_ACCOUNT=	scp-fs2open
GH_PROJECT=	wxLauncher
USE_SDL=	sdl2

CMAKE_ARGS+=	-DRESOURCES_PATH:STRING="${DATADIR}"

DESKTOP_ENTRIES="wxLauncher" "${COMMENT}" \
		"${PORTNAME}" "${PORTNAME}" \
		"Game;" false

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDATA=	*
PORTDOCS=	Authors.md License.txt ReadMe*.md Thanks.txt

OPTIONS_DEFINE=	DEBUG DOCS JOYSTICK WX3
OPTIONS_DEFAULT=	JOYSTICK WX3

JOYSTICK_DESC=	Build with joystick support
WX3_DESC=	Build with using wxWidgets 3.0+ version

DEBUG_CXXFLAGS_OFF=	-DNDEBUG
JOYSTICK_CMAKE_ON=	-DUSE_JOYSTICK:BOOL=ON
JOYSTICK_CMAKE_OFF=	-DUSE_JOYSTICK:BOOL=OFF
WX3_USES=	compiler:c++11-lib
WX3_USE=	WX=3.0+
WX3_CMAKE_ON=	-DWXVER:STRING="3.0"
WX3_CXXFLAGS=	-std=c++11

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
