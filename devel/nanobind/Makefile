PORTNAME=	nanobind
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
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

do-test: # test fails because it doesn't create the PyInit_xx function
	@cd ${WRKSRC} && \
		${CXX} ${CXXFLAGS} ${LDFLAGS} -shared -o ${FILESDIR}/myext.cpp -o myext${PYTHON_EXT_SUFFIX}.so -L${LOCALBASE}/lib -lnanobind && \
		${CP} ${FILESDIR}/test.py . && \
		${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
