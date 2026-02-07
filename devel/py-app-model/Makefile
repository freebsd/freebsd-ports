PORTNAME=	app-model
DISTVERSION=	0.5.0
CATEGORIES=	devel science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic application schema implemented in python
WWW=		https://app-model.readthedocs.io/en/latest/ \
		https://github.com/pyapp-kit/app-model

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}in-n-out>=0.1.5:devel/py-in-n-out@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psygnal>=0.10:devel/py-psygnal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-compat>=0.1.1:devel/py-pydantic-compat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.8:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}QtPy>0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}superqt>0:x11-toolkits/py-superqt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-qt>0:devel/py-pytest-qt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonticon-fontawesome6>0:x11-toolkits/py-fonticon-fontawesome6@${PY_FLAVOR}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pyconify>0:devel/py-pyconify@${PY_FLAVOR} # optional dependency in x11-toolkits/py-superqt

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests crash, see https://github.com/pyapp-kit/app-model/issues/228

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
