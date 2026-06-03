PORTNAME=	ikos
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Static analyzer for C/C++ based on theory of abstract interpretation
WWW=		https://github.com/NASA-SW-VnV/ikos

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.pdf

BROKEN_armv7=	configure fails: error when running a program linked with GMP: Segmentation fault

BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
LIB_DEPENDS=	libapron.so:math/apron \
		libboost_thread.so:devel/boost-libs \
		libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libppl.so:devel/ppl \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}

USES=		cmake ncurses python sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	NASA-SW-VnV
USE_LDCONFIG=	yes

LLVM_VERSION=	14 # only llvm-14 is currently supported

CXXFLAGS+=	-DNDEBUG # https://github.com/NASA-SW-VnV/ikos/issues/36, it also breaks with assert without NDEBUG

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	INSTALL_PYTHON_VIRTUALENV
CMAKE_ARGS=	-DLLVM_CONFIG_EXECUTABLE:PATH=${LOCALBASE}/bin/llvm-config${LLVM_VERSION} \
		-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD} \
		-DPYTHON_VENV_EXECUTABLE:STRING=${PYTHON_CMD}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-configure: # workaround for the problem that --color-diagnostics gets into the linker command lines
	@${REINPLACE_CMD} 's|-Wl,--color-diagnostics| |' ${BUILD_WRKSRC}/build.ninja

post-install:
	# install the local python module 'ikos'
	@${MKDIR} ${STAGEDIR}${DATADIR}/python
	cd ${BUILD_WRKSRC}/analyzer/python && \
		${COPYTREE_SHARE} ikos ${STAGEDIR}${DATADIR}/python
	${CP} ${WRKSRC}/analyzer/python/ikos/*.py ${STAGEDIR}${DATADIR}/python/ikos
	cd ${WRKSRC}/analyzer/python/ikos && \
		${COPYTREE_SHARE} view ${STAGEDIR}${DATADIR}/python/ikos
	# expand the token
	${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' ${STAGEDIR}${PREFIX}/bin/ikos

# use clang corresponding to the used llvm version
CPP=		clang-cpp${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}

.include <bsd.port.mk>
