PORTNAME=	moodbar
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/exaile/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Generates mood files from audio files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3
TEST_DEPENDS=	${PYNUMPY}

USES=		compiler:c++14-lang gnome meson pkgconfig python:3.5+,test \
		shebangfix tar:xz
USE_GNOME=	glib20
USE_GSTREAMER1=	yes good ogg vorbis

PLIST_FILES=	bin/moodbar
SHEBANG_FILES=	test.py

.include <bsd.port.mk>
