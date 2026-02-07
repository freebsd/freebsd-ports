PORTNAME=	natron
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1-pre2
PORTREVISION=	3
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Compositing software Video
WWW=		https://natrongithub.github.io/

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libcairo.so:graphics/cairo \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpyside2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/pyside2@${PY_FLAVOR} \
		libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR}

RUN_DEPENDS=	${LOCALBASE}/OFX/Plugins/Shadertoy.ofx.bundle/Contents/Info.plist:graphics/openfx-misc \
		${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/Info.plist:graphics/openfx-arena \
		ffmpeg>0:multimedia/ffmpeg

USES=		cmake compiler:c++17-lang desktop-file-utils pkgconfig python \
		qt:5 shared-mime-info shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	Natron
GH_TUPLE=	NatronGitHub:google-breakpad:9474c3f7f9939391f281d46c42bfe20cc0f0abd9:google_breakpad/libs/google-breakpad \
		NatronGitHub:google-mock:17945db42c0b42496b2f3c6530307979f2e2a5ce:google_mock/Tests/google-mock \
		NatronGitHub:google-test:50d6fc317c843a2e40dbf08c2efd3f068801ae6d:google_test/Tests/google-test \
		NatronGitHub:OpenColorIO-Configs:557b981:OpenColorIO_Configs/OpenColorIO-Configs \
		NatronGitHub:openfx:0759758d0fb57932b5c4698fff9ef6b4a3132309:openfx/libs/OpenFX \
		NatronGitHub:SequenceParsing:3c93fcc488632b0bdfeee3181586809932357598:SequenceParsing/libs/SequenceParsing \
		NatronGitHub:tinydir:3aae922:tinydir/libs/SequenceParsing/tinydir

USE_PYTHON=	flavors
USE_QT=		concurrent core gui network widgets buildtools:build qmake:build
USE_XORG=	ice pixman sm x11 xext

SHEBANG_FILES=	OpenColorIO-Configs/nuke-default/make.py

BINARY_ALIAS=	python-config=python${PYTHON_VER}-config \
		python=python${PYTHON_VER} \
		sed=gsed

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
