PORTNAME=	nanobind
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny and efficient C++/Python bindings (C++ version)
WWW=		https://nanobind.readthedocs.io/en/latest/ \
		https://github.com/wjakob/nanobind

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	robin-map>0:devel/robin-map
RUN_DEPENDS=	robin-map>0:devel/robin-map
TEST_DEPENDS=	gmake:devel/gmake

USES=		cmake localbase python:test

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob

CMAKE_ARGS=	-DNB_INSTALL_DATADIR=${PREFIX}
CMAKE_ON=	NB_CREATE_INSTALL_RULES
CMAKE_OFF=	NB_USE_SUBMODULE_DEPS \
		NB_TEST_FREE_THREADED \
		NB_TEST \
		CMAKE_SKIP_INSTALL_RULES
CXXFLAGS+=	-I${WRKSRC}/include \
		-I${PYTHON_INCLUDEDIR}

NO_ARCH=	yes

do-install:
	# install manually because the default framework-provided install op fails for some reason
	cd ${BUILD_WRKSRC} && \
		${SETENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} install
	# remove unnecessary files
	@${RM} \
		${STAGEDIR}${PREFIX}/cmake/darwin-ld-cpython.sym \
		${STAGEDIR}${PREFIX}/cmake/darwin-ld-pypy.sym \
		${STAGEDIR}${DATADIR}/__init__.py \
		${STAGEDIR}${DATADIR}/__main__.py

do-test:
	@cd ${WRKSRC} && \
		${RM} -r test && \
		${MKDIR} test && \
		cd test && \
		${CP} ${FILESDIR}/CMakeLists.txt ${FILESDIR}/my_ext.cpp . && \
		cmake -DCMAKE_PREFIX_PATH="${STAGEDIR}${PREFIX}" . && \
		${SETENV} CXXFLAGS="${CXXFLAGS} -I${STAGEDIR}${PREFIX}/include" ${GMAKE} -j ${MAKE_JOBS_NUMBER} && \
		if [ `${PYTHON_CMD} -c "import my_ext; print(my_ext.add(1, 2))"` = 3 ]; then \
			${ECHO} "Test succeeded"; \
		else \
			${ECHO} "Test failed"; \
			return 1; \
		fi

# cmake installs files into non-standard locations, see https://github.com/wjakob/nanobind/issues/810
# hostile upstream, do not create bug reports

.include <bsd.port.mk>
