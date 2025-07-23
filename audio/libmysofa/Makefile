PORTNAME=	libmysofa
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.3
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	SOFA (Spatially Oriented Format for Acoustics) file reader
WWW=		https://github.com/hoene/libmysofa

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	node:www/node

USES=		cmake cpe
CPE_VENDOR=	symonics
USE_GITHUB=	yes
GH_ACCOUNT=	hoene
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-${DISTVERSION}/tests \
			--exclude ${PORTNAME}-${DISTVERSION}/windows \
			--no-same-owner --no-same-permissions

OPTIONS_DEFINE=		STATIC TEST
OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=		yes

STATIC_CMAKE_BOOL=	BUILD_STATIC_LIBS

TEST_BUILD_DEPENDS=	cunit>0:devel/cunit
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test
TEST_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-tests_compare.sh \
			${PATCHDIR}/extrapatch-tests_compareIgnoreNew.sh

# The tests are expected to be in ../tests relative to the build
# directory and the build results are expected to be in build/ relative
# to ${WRKSRC}.  USES=cmake does not allow overwriting ${WRKDIR}/.build
# as the build directory.
post-extract-TEST-on:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    -C ${WRKDIR} --include ${PORTNAME}-${DISTVERSION}/tests \
	    --no-same-owner --no-same-permissions
	@${RLN} ${WRKSRC}/build ${CONFIGURE_WRKSRC}

.include <bsd.port.mk>
