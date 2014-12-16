# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	wxlauncher
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	lightside@gmx.com
COMMENT=	Multi-platform launcher for the Freespace 2 Source Code Project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPLv2.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:${PORTSDIR}/textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	wxLauncher
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	d251770
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake:outsource openal python:2,build
USE_SDL=	sdl
USE_WX=		2.8
WX_UNICODE=	yes
CMAKE_ARGS+=	-DRESOURCES_PATH:STRING="${DATADIR}"

PORTDATA=	*
PORTDOCS=	Authors.txt License.txt ReadMe*.txt Thanks.txt

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="wxLauncher" "${COMMENT}" \
		"${PORTNAME}" "${PORTNAME}" \
		"Game;" false

OPTIONS_DEFINE=	DOCS JOYSTICK
OPTIONS_DEFAULT=	JOYSTICK
JOYSTICK_DESC=	Build with joystick support
JOYSTICK_CMAKE_ON=	-DUSE_JOYSTICK:BOOL=ON
JOYSTICK_CMAKE_OFF=	-DUSE_JOYSTICK:BOOL=OFF

.include <bsd.port.options.mk>

post-patch: .SILENT
# The GetPlatformDefaultConfigFilePath function used as extern inside of
# ${WRKSRC}/code/apis/PlatformProfileManagerShared.cpp file
	${REINPLACE_CMD} -e 's|^inline wxFileName|extern wxFileName|' \
		${WRKSRC}/code/apis/FileProfileManager.cpp
# Change version_strings.cpp.in file, based on GH_TAGNAME, without using hg
	${REINPLACE_CMD} -e '/find_program(HG_EXECUTABLE/d ; \
		/version_strings.cpp will be generated/d' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|123456789abc+ unknown custom tip|${GH_TAGNAME}|' \
		${WRKSRC}/code/global/version_strings.cpp.in

pre-install:
	${INSTALL_DATA} ${WRKSRC}/onlinehelp/images/header.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
