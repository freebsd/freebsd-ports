PORTNAME=	fooyin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	audio multimedia

PATCH_SITES=	https://github.com/fooyin/fooyin/commit/
PATCHFILES=	a7388331090465ae9c22600bee4769d4c00bbc53.patch:-p1 \
		318f2e00952f37e1d237789d7b2605f05639c687.patch:-p1

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	foobar2000 inspired audio player
WWW=		https://github.com/fooyin/fooyin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=  armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Fails to build on 32-bit platforms with various errors

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libgme.so:audio/libgme \
		libicui18n.so:devel/icu \
		libkdsingleapplication-qt6.so:devel/kdsingleapplication \
		libtag.so:audio/taglib

USES=		cmake compiler:c++20-lang desktop-file-utils gl libarchive \
		pkgconfig qt:6 sdl
USE_GL=		opengl
USE_QT=		base svg tools:build
USE_SDL=	sdl2

USE_GITHUB=	yes

CMAKE_OFF=	BUILD_ALSA \
		BUILD_CCACHE \
		BUILD_LIBVGM \
		CMAKE_CXX_EXTENSIONS
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_ALSA \
		CMAKE_DISABLE_FIND_PACKAGE_LibVgm \
		CMAKE_DISABLE_FIND_PACKAGE_OpenMpt \
		CMAKE_DISABLE_FIND_PACKAGE_PipeWire \
		CMAKE_DISABLE_FIND_PACKAGE_SndFile

.include <bsd.port.mk>
