PORTNAME=	bliss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0-6
DISTVERSIONSUFFIX=	-ga443635
CATEGORIES=	audio
PKGNAMESUFFIX=	-music-analyzer

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multithreaded C library used to compute distance between songs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfftw3.so:math/fftw3

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Polochon-street
USE_LDCONFIG=	yes

PLIST_FILES=	include/bliss.h \
		lib/libbliss.so

.include <bsd.port.mk>
