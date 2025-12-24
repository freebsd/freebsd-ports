PORTNAME=	bliss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0-209
DISTVERSIONSUFFIX=	-g3464680
PORTREVISION=	2
CATEGORIES=	audio
PKGNAMESUFFIX=	-music-analyzer

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multithreaded C library used to compute distance between songs
WWW=		https://github.com/Polochon-street/bliss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Does not build with ffmpeg > 6

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfftw3.so:math/fftw3

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Polochon-street
USE_LDCONFIG=	yes

PLIST_FILES=	include/bliss.h \
		lib/libbliss.so

.include <bsd.port.mk>
