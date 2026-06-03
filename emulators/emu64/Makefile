PORTNAME=	emu64
DISTVERSION=	5.1.0
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Commodore 64 emulator
WWW=		https://github.com/ThKattanek/emu64

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg \
		libquazip1-qt6.so:archivers/quazip@qt6

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl pkgconfig \
		qmake:outsource qt:6 sdl
USE_GL=		gl glu
USE_QT=		base 5compat tools translations

DOS2UNIX_GLOB=	*.cpp *.h

USE_SDL=	sdl2 image2
USE_GITHUB=	yes
GH_ACCOUNT=	ThKattanek
GH_TAGNAME=	3c636ef

OPTIONS_DEFINE=	DOCS

.if !exists(/usr/include/omp.h)
USE_GCC=	yes
.endif

.include <bsd.port.mk>
