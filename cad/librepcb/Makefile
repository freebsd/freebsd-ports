PORTNAME=	librepcb
DISTVERSION=	1.1.0
PORTREVISION=	1
DISTVERSIONSUFFIX=	-source
CATEGORIES=	cad
MASTER_SITES=	https://download.librepcb.org/releases/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schematic and PCB editing software
WWW=		https://librepcb.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg4 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libtbb.so:devel/onetbb \
		libTKService.so:cad/opencascade

USES=		cmake:testing compiler:c++11-lang desktop-file-utils gl \
		localbase:ldflags qt:5 shared-mime-info xorg zip
USE_QT=		concurrent core declarative gui network \
		opengl printsupport quickcontrols2 sql svg xml widgets \
		buildtools:build linguisttools:build testlib:build qmake:build
USE_GL=		gl glu
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CMAKE_ARGS=		-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=274834
CMAKE_OFF=		BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=

post-test: # run tests
	@${BUILD_WRKSRC}/tests/unittests/librepcb-unittests

.include <bsd.port.mk>
