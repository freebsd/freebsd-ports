PORTNAME=	argcomplete
PORTVERSION=	3.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bash tab completion for argparse
WWW=		https://kislyuk.github.io/argcomplete/ \
		https://github.com/kislyuk/argcomplete

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		ruff:devel/ruff

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

SHEBANG_FILES=	argcomplete/scripts/*.py \
		test/prog

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' ${WRKSRC}/test/test.py

.include <bsd.port.mk>
