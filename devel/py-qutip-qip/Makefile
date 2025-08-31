PORTNAME=	qutip-qip
DISTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QuTiP quantum information processing package
WWW=		https://github.com/qutip/qutip-qip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qutip>=4.6:devel/py-qutip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} # optional dependency required for tests
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyqir>0:misc/py-pyqir@${PY_FLAVOR} # optional

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/qutip/qutip-qip/issues/214

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

NO_ARCH=	yes

post-patch:
	@cd ${WRKSRC} && ${ECHO} ${DISTVERSION} > VERSION

.include <bsd.port.mk>
