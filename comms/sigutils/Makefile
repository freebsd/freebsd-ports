PORTNAME=	sigutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small signal processing utility library
WWW=		https://github.com/BatchDrake/sigutils

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libsndfile.so:audio/libsndfile \
		libvolk.so:devel/volk

USES=		cmake:noninja pkgconfig # ninja breaks
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	BatchDrake

do-test: # 5 tests fail, see https://github.com/BatchDrake/sigutils/issues/32
	@cd ${BUILD_WRKSRC} && ./sutest

.include <bsd.port.mk>
