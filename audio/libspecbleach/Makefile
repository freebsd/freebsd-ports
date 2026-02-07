PORTNAME=	libspecbleach
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for audio noise reduction
WWW=		https://github.com/lucianodato/libspecbleach

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		meson pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lucianodato

PLIST_FILES=	include/specbleach_adenoiser.h \
		include/specbleach_denoiser.h \
		lib/libspecbleach.so \
		lib/libspecbleach.so.0 \
		lib/libspecbleach.so.0.2.0 \
		libdata/pkgconfig/libspecbleach.pc

.include <bsd.port.mk>
