PORTNAME=	libsonic
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.2.0-65
DISTVERSIONSUFFIX=	-gba33141
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple library to speed up or slow down speech

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		gmake localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	waywardgeek
GH_PROJECT=	sonic

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" USE_SPECTROGRAM=1
CFLAGS+=	-ansi -fPIC -pthread -Wno-unused-function -DSONIC_SPECTROGRAM

CONFLICTS_INSTALL=	sonic # bin/sonic

PLIST_FILES=	bin/sonic \
		include/sonic.h \
		lib/libsonic.a \
		lib/libsonic.so \
		lib/libsonic.so.0 \
		lib/libsonic.so.0.3.0

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/sonic \
		${STAGEDIR}${PREFIX}/lib/libsonic.so.0.3.0

.include <bsd.port.mk>
