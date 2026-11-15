PORTNAME=	detect-it-easy
DISTVERSION=	4.0.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/horsicq/DIE-engine/releases/download/${DISTVERSION}/
DISTNAME=	die_sourcecode_${DISTVERSION}

MAINTAINER=	res2500@ukr.net
COMMENT=	File type identification and binary analysis utility
WWW=		https://github.com/horsicq/Detect-It-Easy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang desktop-file-utils dos2unix gl qt:6

DOS2UNIX_FILES=	dep/XOptions/xoptions.cpp

USE_GL=		opengl
USE_QT=		base declarative svg tools:build

CONFIGURE_ENV+=	PATH=${LOCALBASE}/lib/qt6/bin:${PATH}

CMAKE_ARGS=	-DX_RESOURCES=share/die

CXXFLAGS+=	-Wno-register

post-patch:
	${FIND} ${WRKSRC} -type d -name .vscode \
		-prune -exec ${RM} -r {} +
	@${REINPLACE_CMD} \
		-e 's|/opt/detect-it-easy|${PREFIX}/share/die|g' \
		${WRKSRC}/src/console/main_console.cpp \
		${WRKSRC}/src/gui/main_gui.cpp \
		${WRKSRC}/src/lite/main_lite.cpp

.include <bsd.port.mk>
