PORTNAME=	emu64
DISTVERSION=	5.1.0
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Commodore 64 emulator
WWW=		https://github.com/ThKattanek/emu64

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libquazip1-qt5.so:archivers/quazip@qt5 \
		libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl pkgconfig \
		qmake:outsource qt:5 sdl
USE_GL=		gl glu
USE_QT=		core gui network widgets buildtools:build linguisttools:build

DOS2UNIX_GLOB=	*.cpp *.h

USE_SDL=	sdl2 image2
USE_GITHUB=	yes
GH_ACCOUNT=	ThKattanek

OPTIONS_DEFINE=	DOCS

.if !exists(/usr/include/omp.h)
USE_GCC=	yes
.endif

.include <bsd.port.mk>
