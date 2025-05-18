PORTNAME=	poetry-plugin-shell
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	poetry_plugin_shell-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Poetry plugin to run subshell with virtual environment activated
WWW=		https://github.com/python-poetry/poetry-plugin-shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>=4.7.0<5:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=2.0<3:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.5<2:devel/py-shellingham@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
