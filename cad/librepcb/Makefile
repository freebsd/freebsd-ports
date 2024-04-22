PORTNAME=	librepcb
DISTVERSION=	1.0.0
DISTVERSIONSUFFIX=	-source
PORTREVISION=	1
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
		libTKService.so:cad/opencascade

USES=		cmake compiler:c++11-lang desktop-file-utils gl \
		localbase:ldflags qt:5 shared-mime-info xorg zip
USE_QT=		concurrent core declarative gui network \
		opengl printsupport quickcontrols2 sql svg xml widgets \
		buildtools:build linguisttools:build testlib:build qmake:build
USE_GL=		gl glu
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=274834

.include <bsd.port.mk>
