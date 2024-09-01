PORTNAME=	fooyin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	audio multimedia

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	foobar2000 inspired audio player
WWW=		https://github.com/fooyin/fooyin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

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
