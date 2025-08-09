PORTNAME=	lfortran
DISTVERSIONPREFIX=	v
DISTVERSION=	0.54.0
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Modern interactive Fortran compiler built on top of LLVM
WWW=		https://lfortran.org/

LICENSE=	BSD3CLAUSE

BROKEN_i386=	sizeof(YYSTYPE) != sizeof(Vec<AST::ast_t*>)

BUILD_DEPENDS=	bash:shells/bash		\
		re2c>0:devel/re2c		\
		dwarfdump:devel/dwarfdump	\
		pandoc:textproc/hs-pandoc	\
		rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libfmt.so:devel/libfmt	\
		libzstd.so:archivers/zstd	\
		libunwind.so:devel/libunwind	\
		libkokkoscore.so:devel/kokkos
RUN_DEPENDS=	dwarfdump:devel/dwarfdump

USE_GITHUB=	yes

USES=		bison cmake:testing compiler:c++17-lang llvm:20,lib pkgconfig	\
		python:build ssl shebangfix
SHEBANG_GLOB=	*.py *.sh
BINARY_ALIAS=	python=${PYTHON_CMD}
CMAKE_ON=	LFORTRAN_BUILD_ALL WITH_DWARFDUMP WITH_FMT WITH_JSON	\
		WITH_KOKKOS WITH_LINKH WITH_LLVM WITH_LLVM_STACKTRACE	\
		WITH_MLIR WITH_STACKTRACE WITH_UNWIND
CMAKE_ARGS=	-DLLVM_INSTALL_DIR:PATH="${LOCALBASE}/llvm${LLVM_VERSION}"	\
		-DMLIR_DIR:PATH="${LOCALBASE}/llvm${LLVM_VERSION}/lib/cmake/mlir"	\
		-DCMAKE_PREFIX_PATH:PATH="${LOCALBASE}/llvm${LLVM_VERSION};${CMAKE_PREFIX_PATH}"
USE_LDCONFIG=	yes

LLVM_VERSION=	20

OPTIONS_DEFINE=	EXAMPLES # NB
# NB is broken ATM
NB_DESC=	Documentation as a Jupyter notebook
NB_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}	\
			sphinx-intl:textproc/py-sphinx@${PY_FLAVOR}	\
			myst-inv:textproc/py-myst-parser@${PY_FLAVOR}   \
			jupyter:devel/py-jupyter-core@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}nbsphinx>0:textproc/py-nbsphinx@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}sphinx_material>0:textproc/py-sphinx-material@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}sphinx-copybutton>0:textproc/py-sphinx-copybutton@${PY_FLAVOR}	\

PORTEXAMPLES=	*

# Xeus: version 5.1.0 is required and xeus-zmq 3.0.0
# + xtl-quant-stack + cppzmq + nlohmann_json + LibUUID + libzmq4
# See https://github.com/lfortran/lfortran/issues/1255
#BUILD_DEPENDS+=	xtl-quant-stack>=0.7:devel/xtl-quant-stack	\
#		nlohmann-json>0:devel/nlohmann-json	\
#		cppzmq>=4.8.1:net/cppzmq
#LIB_DEPENDS+=	libxeus.so:devel/xeus	\
#		libzmq.so:net/libzmq4	\
#		libxeus-zmq.so:devel/xeus-zmq	\
#		libuuid.so:misc/libuuid
CMAKE_OFF+=	WITH_XEUS

# BFD:
USE_BINUTILS=	yes
CMAKE_ON+=	WITH_BFD
LIB_DEPENDS+=	libbfd.so:devel/binutils

PLIST_SUB=	VER=${PORTVERSION}

pre-configure:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/version

do-build-NB-on:
	(cd ${WRKSRC}/doc && ${PYTHON_CMD} build.py)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
