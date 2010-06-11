# Ports collection makefile for:  boost-pyste
# Date Created:			  16 Novemeber 2009
# Whom:				  Alexander Churanov <churanov.port.maintainer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	boost-pyste
COMMENT=	Boost.Python code generator

CONFLICTS+=	boost-python-libs-1.3* boost-python-libs-1.40
USE_BZIP2=	yes
USE_PYTHON=	2.4+

OPTIONS=	VERBOSE_BUILD	"Show compiler messages"	off \
		DEBUG		"Build debugging symbols"	off \
		OPTIMIZED_CFLAGS "Enable -O3 optimization"	off

INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	Pyste
PYDISTUTILS_PKGVERSION=	0.9.10

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/boost-all/common.mk"
.include "${PORTSDIR}/devel/boost-all/compiled.mk"

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

RUN_DEPENDS+=	${LOCALBASE}/lib/libboost_python.so.${BOOST_SHARED_LIB_VER}:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree

RUN_DEPENDS+=	gccxml:${PORTSDIR}/devel/gccxml
BUILD_DEPENDS+=	${BJAM}:${PORTSDIR}/devel/boost-jam
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree

post-patch: customize-boost-build

post-configure:
# Configure pyste, the Boost.Python code generator
	@cd ${BUILD_WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		config ${PYDISTUTILS_CONFIGUREARGS}

do-build:
# Build pyste, the Boost.Python code generator
	cd ${BUILD_WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		build ${PYDISTUTILS_BUILDARGS}

do-install:
# Install pyste, the Boost.Python code generator
	cd ${WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		install ${PYDISTUTILS_INSTALLARGS}

.include <bsd.port.post.mk>
