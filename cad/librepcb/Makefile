PORTNAME=	librepcb
DISTVERSION=	1.2.0
PORTREVISION=	2
DISTVERSIONSUFFIX=	-source
CATEGORIES=	cad
MASTER_SITES=	https://download.librepcb.org/releases/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schematic and PCB editing software
WWW=		https://librepcb.org/ \
		https://github.com/LibrePCB/LibrePCB/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg4 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libtbb.so:devel/onetbb \
		libTKService.so:cad/opencascade

USES=		cmake:testing compiler:c++17-lang desktop-file-utils gl \
		localbase:ldflags qt:5 shared-mime-info xorg zip
USE_GL=		gl glu
USE_QT=		buildtools:build concurrent core declarative gui \
		linguisttools:build network opengl printsupport qmake:build \
		quickcontrols2 sql svg testlib:build xml widgets
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CMAKE_ARGS=		-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=274834
CMAKE_OFF=		BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=

post-test: # run tests
	@${BUILD_WRKSRC}/tests/unittests/librepcb-unittests

.include <bsd.port.mk>
