PORTNAME=	pandaresampler
DISTVERSION=	0.2.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/swesterfeld/pandaresampler/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast factor 2 resampler for audio signals
WWW=		https://github.com/swesterfeld/pandaresampler

LICENSE=	MPL20

BUILD_DEPENDS=	fftw3>0:math/fftw3 \
		fftw3-float>0:math/fftw3-float \
		zita-resampler>0:audio/zita-resampler # only for tests, see https://github.com/swesterfeld/pandaresampler/issues/2

USES=		gmake localbase:ldflags pkgconfig

GNU_CONFIGURE=	yes

PLIST_FILES=	include/pandaresampler.hh \
		lib/libpandaresampler.a

do-install: # workaround for https://github.com/swesterfeld/pandaresampler/issues/1
	${INSTALL_DATA} ${WRKSRC}/lib/pandaresampler.hh ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/.libs/libpandaresampler.a ${STAGEDIR}${PREFIX}/lib

# relevant issues:
# * https://github.com/swesterfeld/pandaresampler/issues/3: Please allow to build a shared library with --enable-shared
# * https://github.com/swesterfeld/pandaresampler/issues/2: Please don't build tests by default

.include <bsd.port.mk>
