# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	emu64
PORTVERSION=	5.0.18
CATEGORIES=	emulators

MAINTAINER=	felix@palmen-it.de
COMMENT=	Commodore 64 emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libquazip5.so:archivers/quazip \
		libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig \
		qmake:outsource qt:5 sdl
USE_GL=		gl glu
USE_QT=		core gui widgets buildtools_build linguisttools_build

USE_SDL=	sdl2 image2
USE_GITHUB=	yes
GH_ACCOUNT=	ThKattanek

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
