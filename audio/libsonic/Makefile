# $FreeBSD$

PORTNAME=	libsonic
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.2.0-51
DISTVERSIONSUFFIX=	-ge4a56ec
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple library to speed up or slow down speech

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	waywardgeek
GH_PROJECT=	sonic
USE_LDCONFIG=	yes

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}" PREFIX="${PREFIX}"
CFLAGS+=	-ansi -fPIC -pthread -Wno-unused-function -DSONIC_SPECTROGRAM

PLIST_FILES=	bin/sonic \
		include/sonic.h \
		lib/libsonic.so \
		lib/libsonic.so.0 \
		lib/libsonic.so.0.3.0

.include <bsd.port.mk>
