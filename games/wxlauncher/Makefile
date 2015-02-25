# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	wxlauncher
PORTVERSION=	0.9.5
CATEGORIES=	games

MAINTAINER=	lightside@gmx.com
COMMENT=	Multi-platform launcher for the Freespace 2 Source Code Project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPLv2.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:${PORTSDIR}/textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	wxLauncher
GH_COMMIT=	7ee46df
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake:outsource openal python:2,build
USE_SDL=	sdl
WX_UNICODE=	yes
CMAKE_ARGS+=	-DRESOURCES_PATH:STRING="${DATADIR}"

PORTDATA=	*
PORTDOCS=	Authors.txt License.txt ReadMe*.txt Thanks.txt

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="wxLauncher" "${COMMENT}" \
		"${PORTNAME}" "${PORTNAME}" \
		"Game;" false

OPTIONS_DEFINE=	DOCS JOYSTICK WX3
OPTIONS_DEFAULT=	JOYSTICK
JOYSTICK_DESC=	Build with joystick support
JOYSTICK_CMAKE_ON=	-DUSE_JOYSTICK:BOOL=ON
JOYSTICK_CMAKE_OFF=	-DUSE_JOYSTICK:BOOL=OFF
WX3_DESC=	Build with using wxWidgets 3.0+ version (2.8 otherwise)
WX3_USE=	WX=3.0+
WX3_USE_OFF=	WX=2.8

.include <bsd.port.options.mk>

# Allow to build with using concrete wxWidgets version
.if ${PORT_OPTIONS:MWX3}
SED_RE_WX3=	wxWidgets 2\./,+1d
.else
SED_RE_WX3=	NOT wxWidgets_FOUND/,+3d
.endif

post-patch: .SILENT
# The GetPlatformDefaultConfigFilePath function used as extern inside of
# ${WRKSRC}/code/apis/PlatformProfileManagerShared.cpp file
	${REINPLACE_CMD} -e 's|^inline wxFileName|extern wxFileName|' \
		${WRKSRC}/code/apis/FileProfileManager.cpp
# Fix relative path to OpenAL includes
	${REINPLACE_CMD} -e '/^#include <al/s|al/||' \
		${WRKSRC}/code/apis/OpenALManager.cpp
# Change version_strings.cpp.in file, based on GH_TAGNAME, without using git
	${REINPLACE_CMD} -e '/find_program(GIT_EXECUTABLE/d ; \
		/version_strings.cpp will be generated/d ; /${SED_RE_WX3}' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|123456789abc+ unknown custom tip|${GH_TAGNAME}|' \
		${WRKSRC}/code/global/version_strings.cpp.in
.if ${PORT_OPTIONS:MWX3}
# Fix ambiguity between wxCStrData and wxString
	${REINPLACE_CMD} -e 's|item->forum\.c_str|(wxString)&|' \
		${WRKSRC}/code/controls/ModList.cpp
.endif

pre-install:
	${INSTALL_DATA} ${WRKSRC}/onlinehelp/images/header.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
