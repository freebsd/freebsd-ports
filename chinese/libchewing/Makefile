PORTNAME=	libchewing
PORTVERSION=	0.8.5
CATEGORIES=	chinese textproc
MASTER_SITES=	https://github.com/chewing/libchewing/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chewing intelligent phonetic input method library
WWW=		https://chewing.im/ \
		https://github.com/chewing/libchewing

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing localbase:ldflags pkgconfig sqlite tar:zst

CMAKE_OFF=	BUILD_INFO \
		BUILD_TESTING \
		ENABLE_GCOV \
		USE_VALGRIND \
		WITH_INTERNAL_SQLITE3 \
		WITH_RUST
CMAKE_ON=	BUILD_SHARED_LIBS \
		NO_UNDEFINED \
		WITH_SQLITE3
CMAKE_TESTING_PARALLEL_LEVEL=	1	# https://github.com/chewing/libchewing/issues/293
USE_LDCONFIG=	yes

.include <bsd.port.mk>
