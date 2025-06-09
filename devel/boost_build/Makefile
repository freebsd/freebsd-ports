PORTNAME=	build
DISTVERSION=	5.3.2
CATEGORIES=	devel
PKGNAMEPREFIX=	boost-

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Extensible cross-platform build tool suite
WWW=		https://boostorg.github.io/build/index.html

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/bin/bjam:devel/boost-jam

USES=		compiler:c++11-lang python:test shebangfix tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	boostorg
GH_PROJECT=	build
GH_TAGNAME=	be69c44

DATADIR=	${PREFIX}/share/b2

CONFLICTS_INSTALL=	b2

SHEBANG_GLOB=	*.py

SUB_FILES=	pkg-message

MAKE_CMD=	./bootstrap.sh
ALL_TARGET=	${CHOSEN_COMPILER_TYPE} ${WITH_DEBUG:D--debug}
MAKE_FLAGS=	--cxx="${CXX}" --cxxflags="${CXXFLAGS:N-O*}" BOOST_BUILD_PATH=${DATADIR}
_MAKE_JOBS=	#
MAKEFILE=	#
INSTALL_ENV=	BOOST_BUILD_PATH=${DATADIR}

do-install:
	cd ${WRKSRC} && ./b2 toolset=${CHOSEN_COMPILER_TYPE} install --prefix=${STAGEDIR}${PREFIX}

do-test: # test target fails: https://github.com/boostorg/build/issues/698
	cd ${WRKSRC} && ./b2 toolset=${CHOSEN_COMPILER_TYPE} test --prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
