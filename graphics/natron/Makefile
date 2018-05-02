# $FreeBSD$

PORTNAME=	natron
PORTVERSION=	2.3.4
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Video compositing software

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64
BUILD_DEPENDS=	python-config:lang/python \
				pyside${PYTHON_PKGNAMESUFFIX}>0:devel/pyside
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

USES=	pkgconfig python qmake shebangfix desktop-file-utils shared-mime-info \
		gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	MrKepzie
GH_PROJECT=	Natron
GH_TUPLE=	MrKepzie:OpenColorIO-Configs:Natron-v2.3:OpenColorIO_Configs/OpenColorIO-Configs \
			MrKepzie:google-test:50d6fc3:google_test/Tests/google-test \
			MrKepzie:google-mock:17945db:google_mock/Tests/google-mock \
			MrKepzie:SequenceParsing:4b5e605:SequenceParsing/libs/SequenceParsing \
			MrKepzie:tinydir:60f0905:tinydir/libs/SequenceParsing/tinydir \
			devernay:openfx:3056fd6:openfx/libs/OpenFX

USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build network opengl
USE_XORG=	x11 pixman
USE_GL=		gl

SHEBANG_FILES=	OpenColorIO-Configs/nuke-default/make.py

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
