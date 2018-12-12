# $FreeBSD$

PORTNAME=	natron
PORTVERSION=	2.3.14
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Video compositing software

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

ONLY_FOR_ARCHS=	amd64
BUILD_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>0:devel/pyside
RUN_DEPENDS=	${LOCALBASE}/OFX/Plugins/IO.ofx.bundle/Contents/Info.plist:graphics/openfx-io \
				${LOCALBASE}/OFX/Plugins/Shadertoy.ofx.bundle/Contents/Info.plist:graphics/openfx-misc \
				${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/Info.plist:graphics/openfx-arena
LIB_DEPENDS=	libcairo.so:graphics/cairo \
				libexpat.so:textproc/expat2 \
				libboost_system.so:devel/boost-libs \
				libshiboken-${PYTHON_VERSION}.so:devel/shiboken \
				libfontconfig.so:x11-fonts/fontconfig \
				libavformat.so:multimedia/ffmpeg \
				libpyside-${PYTHON_VERSION}.so:devel/pyside \
				libfreetype.so:print/freetype2

USES=	pkgconfig python:2.7 qmake qt:4 shebangfix desktop-file-utils shared-mime-info \
		gettext-runtime desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	Natron
GH_TUPLE=	NatronGitHub:openfx:a85dc34:openfx/libs/OpenFX \
			NatronGitHub:google-test:50d6fc3:google_test/Tests/google-test \
			NatronGitHub:google-mock:17945db:google_mock/Tests/google-mock \
			NatronGitHub:google-breakpad:9474c3f:google_breakpad/libs/google-breakpad \
			NatronGitHub:SequenceParsing:9e8b77a:SequenceParsing/libs/SequenceParsing \
			NatronGitHub:tinydir:3aae922:tinydir/libs/SequenceParsing/tinydir \
			NatronGitHub:OpenColorIO-Configs:Natron-v3.0:OpenColorIO_Configs/OpenColorIO-Configs

USE_QT=		corelib gui moc_build qmake_build rcc_build uic_build network opengl
USE_XORG=	x11 pixman
USE_GL=		gl

SHEBANG_FILES=	OpenColorIO-Configs/nuke-default/make.py

BINARY_ALIAS=	python2-config=python${PYTHON_VER}-config

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/OFX/Plugins|${PREFIX}/OFX/Plugins|g' \
		${WRKSRC}/libs/OpenFX/Examples/Makefile.master \
		${WRKSRC}/libs/OpenFX/Support/Plugins/Makefile.master \
		${WRKSRC}/libs/OpenFX/HostSupport/src/ofxhPluginCache.cpp \
		${WRKSRC}/Engine/Settings.cpp
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/Engine/AppManager.cpp \
		${WRKSRC}/Engine/Settings.cpp \
		${WRKSRC}/Natron.spec

.include <bsd.port.mk>
