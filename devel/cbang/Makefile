PORTNAME=	cbang
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C! (cbang) is a library of cross-platform C++ utilities

LICENSE=	LGPL21

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libv8.so:lang/v8		\
		libre2.so:devel/re2		\
		liblz4.so:archivers/liblz4	\
		libevent.so:devel/libevent	\
		libexpat.so:textproc/expat2	\
		libyaml.so:textproc/libyaml	\
		libsnappy.so:archivers/snappy	\
		libsysinfo.so:devel/libsysinfo	\
		libleveldb.so:databases/leveldb

USE_GITHUB=	yes
GH_ACCOUNT=	CauldronDevelopmentLLC

USES=		compiler:c++14-lang localbase mysql:client python:test scons	\
		sqlite ssl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DEBUG DOCS
DEBUG_BUILD_DEPENDS=	gnulibiberty>0:devel/gnulibiberty
DEBUG_LIB_DEPENDS=	libbfd.so:devel/libbfd

MAKE_ARGS+=	cc="${CC}"	\
		cxx="${CXX}"	\
		cxxstd="c++14"	\
		ccflags="${CCFLAGS}"	\
		cxxflags="${CXXFLAGS}"	\
		libpath="${LIBPATH}"	\
		sharedlib=1	\
		prefix="${STAGEDIR}${PREFIX}"	\
		compiler="${CHOSEN_COMPILER_TYPE:C/gcc/gnu/}"	\
		disable_local="zlib bzip2 lz4 sqlite3 expat libevent re2 libyaml"
# With boost in disable_local, libcbang-boost.a is not built
#		disable_local="zlib bzip2 lz4 sqlite3 expat boost libevent re2 libyaml"
MAKE_ENV+=	LIBPATH="${LIBPATH}"	\
		LIBRARY_PATH="${LIBPATH}:${LIBPATH}/mysql"
LIBVER=		1.3.3
PLIST_SUB=	VER=${LIBVER}

TEST_WRKSRC=	${WRKSRC}/tests
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${TEST_ARGS}

pre-configure:
	${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|'	\
		${TEST_WRKSRC}/testHarness

post-install:
	cd ${STAGEDIR}${PREFIX}/lib &&	\
		${LN} -sf libcbang0.so.${LIBVER} libcbang0.so	&&	\
		${LN} -sf libcbang0.so.${LIBVER} libcbang0.so.1
	# Needed to build CAMotics
	${INSTALL_DATA} ${WRKSRC}/include/cbang/config.h	\
		${STAGEDIR}${PREFIX}/include/cbang/
	${INSTALL_DATA} ${WRKSRC}/lib/libcbang-boost.a	\
		${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} config ${STAGEDIR}${DATADIR}

do-test:
	(cd ${TEST_WRKSRC} && ${DO_MAKE_TEST} && ./testHarness)

.include <bsd.port.mk>
