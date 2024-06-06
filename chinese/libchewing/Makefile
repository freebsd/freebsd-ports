PORTNAME=	libchewing
DISTVERSION=	0.8.4
CATEGORIES=	chinese textproc
MASTER_SITES=	https://github.com/chewing/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chewing intelligent phonetic input method library
WWW=		https://chewing.im

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing localbase:ldflags pathfix pkgconfig sqlite tar:zst
USE_LDCONFIG=	yes

# Tests when running in parallel
# https://github.com/chewing/libchewing/issues/293
CMAKE_TESTING_PARALLEL_LEVEL=	1

CMAKE_OFF=	BUILD_INFO \
		BUILD_TESTING \
		WITH_RUST
CMAKE_ON=	WITH_SQLITE3

.include <bsd.port.mk>
