PORTNAME=	nanobind
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0-8
DISTVERSIONSUFFIX=	-gfd22b8c
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny and efficient C++/Python bindings (C++ version)
WWW=		https://github.com/wjakob/nanobind

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	robin-map>0:devel/robin-map
RUN_DEPENDS=	robin-map>0:devel/robin-map

USES=		localbase python

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob

CMAKE_ARGS=	-DNB_INSTALL_DATADIR=""
CMAKE_ON=	NB_CREATE_INSTALL_RULES
CMAKE_OFF=	NB_TEST_FREE_THREADED \
		NB_TEST \
		CMAKE_SKIP_INSTALL_RULES
CXXFLAGS+=	-I${WRKSRC}/include \
		-I${PYTHON_INCLUDEDIR}

do-build: # cmake scripts don't build the shared library
	@cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${CXX} \
			${CXXFLAGS} ${LDFLAGS} \
			-fPIC \
			-shared \
			-Wl,-soname=libnanobind.so \
			-o libnanobind.so \
			nb_combined.cpp

do-install:
	# install headers
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include
	# install shared library
	${INSTALL_LIB} ${WRKSRC}/src/libnanobind.so ${STAGEDIR}${PREFIX}/lib
	# install cmake script
	${MKDIR} ${STAGEDIR}${PREFIX}/cmake
	${INSTALL_DATA} ${WRKSRC}/cmake/nanobind-config.cmake ${STAGEDIR}${PREFIX}/cmake

do-test: # test fails because it doesn't create the PyInit_xx function
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CXX} ${CXXFLAGS} \
			${LDFLAGS} -shared -o ${FILESDIR}/myext.cpp -o myext${PYTHON_EXT_SUFFIX}.so \
			-L${LOCALBASE}/lib -L${STAGEDIR}${PREFIX}/lib -lnanobind && \
		${CP} ${FILESDIR}/test.py . && \
		${PYTHON_CMD} ${FILESDIR}/test.py

# cmake doesn't generate install target, see https://github.com/wjakob/nanobind/issues/775

.include <bsd.port.mk>
