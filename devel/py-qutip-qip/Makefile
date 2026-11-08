PORTNAME=	qutip-qip
DISTVERSION=	0.4.2
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	qutip_qip-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QuTiP quantum information processing package
WWW=		https://github.com/qutip/qutip-qip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16.6:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qutip>=4.6:devel/py-qutip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} LD_PRELOAD=/lib/libgcc_s.so.1 MPLBACKEND=Agg \
		PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

post-patch:
	@cd ${WRKSRC} && ${ECHO} ${DISTVERSION} > VERSION

# tests as of 0.4.2: 506 passed, 15 skipped, 30 warnings in 81.96s (0:01:21)

.include <bsd.port.mk>
