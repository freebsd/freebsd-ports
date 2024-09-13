PORTNAME=	unidep
PORTVERSION=	0.63.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unified Conda and Pip requirements management
WWW=		https://unidep.readthedocs.io/en/latest/ \
		https://github.com/basnijholt/unidep

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PIP_COMPILE RICH TOML
OPTIONS_DEFAULT=TOML
PIP_COMPILE_DESC=	pip-compile integration
RICH_DESC=		Help formatter via rich

PIP_COMPILE_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}pip-tools>=0:devel/py-pip-tools@${PY_FLAVOR}
RICH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rich-argparse>=0:devel/py-rich-argparse@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTOML} && ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
