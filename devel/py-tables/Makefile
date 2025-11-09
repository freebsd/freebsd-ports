PORTNAME=	tables
PORTVERSION=	3.10.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Hierarchical database for Python
WWW=		https://www.pytables.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}numexpr>=1.4.1:math/py-numexpr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-cpuinfo>=0:sysutils/py-py-cpuinfo@${PY_FLAVOR}
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		liblzo2.so:archivers/lzo2 \
		libucl.so:archivers/ucl \
		libblosc2.so:archivers/c-blosc2
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0:devel/py-mock@${PY_FLAVOR}

CONFLICTS_BUILD=	zstd # conflicting version of zstd is bundled

USES=		fortran localbase python
USE_PYTHON=	autoplist concurrent distutils cython

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFINE_amd64=		AVX2

AVX2_DESC=	Enable Haswell New Instructions (AVX2) support

# Explicitly disable AVX2 otherwise it will be automatically enabled if the CPU
# supports it.  If compiled in and run on hosts that have no AVX2 support, it
# will trigger a SIGILL (Illegal instruction)
# See also: https://github.com/PyTables/PyTables/issues/841
AVX2_VARS_OFF=	MAKE_ENV+=DISABLE_AVX2=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/tables/*.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
