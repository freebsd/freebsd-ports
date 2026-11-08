PORTNAME=	envs
DISTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Easy access of environment variables from Python
WWW=		https://github.com/capless/envs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI

CLI_DESC=		Install the envs command-line tool
# the envs command (envs.cli) needs the upstream "cli" extra
CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0.3:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.3:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}terminaltables>=3.1.10:textproc/py-terminaltables@${PY_FLAVOR}

post-patch-CLI-off:
	@${REINPLACE_CMD} -e "/^envs = 'envs\.cli:envs'$$/d" ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
