PORTNAME=	boost-jam

COMMENT=	Build tool from the boost.org
WWW=		https://www.boost.org/

PLIST_FILES=	bin/bjam

LICENSE=	BSL

EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions ${DISTVERSIONPREFIX}${BOOST_MAJOR_VER}_${BOOST_MINOR_VER}_${BOOST_PATCH_VER}/${WRKSRC_SUBDIR}
MAKE_CMD=	./build.sh
ALL_TARGET=	${CHOSEN_COMPILER_TYPE} ${WITH_DEBUG:D--debug}
MAKE_FLAGS=	--cxx="${CXX}" --cxxflags="${CXXFLAGS:N-O*}"
_MAKE_JOBS=	#
MAKEFILE=	#

USES=		compiler:c++11-lang

WRKSRC_SUBDIR=	tools/build/src/engine

.include "${.CURDIR:H}/boost-all/common.mk"

EXTRACT_AFTER_ARGS=${DISTNAME}/${WRKSRC_SUBDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bjam ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
