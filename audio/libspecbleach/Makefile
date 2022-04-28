PORTNAME=	libspecbleach
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for audio noise reduction

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
		libdata/pkgconfig/libspecbleach.pc

.include <bsd.port.mk>
