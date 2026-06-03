PORTNAME=	atracdenc
DISTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/dcherednik/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://code.mastervirt.ru/st/${PORTNAME}/

MAINTAINER=	pkgsup@mastervirt.ru
COMMENT=	ATRAC1 decoder/encoder, ATRAC3 encoder
WWW=		https://github.com/dcherednik/atracdenc/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsndfile.so:audio/libsndfile
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang tar:xz

PLIST_FILES=	bin/atracdenc \
		share/man/man1/atracdenc.1.gz

CMAKE_TESTING_OFF=	CMAKE_DISABLE_FIND_PACKAGE_GTest

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_GTest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/atracdenc

.include <bsd.port.mk>
