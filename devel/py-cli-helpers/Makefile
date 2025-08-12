PORTNAME=	cli-helpers
PORTVERSION=	2.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cli_helpers-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for building command-line apps
WWW=		https://cli-helpers.readthedocs.io/en/stable/ \
		https://github.com/dbcli/cli_helpers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=5.0.5:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.9.0:devel/py-tabulate@${PY_FLAVOR}
# devel/py-tabulate[widechars]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}wcwidth>=0:devel/py-wcwidth@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	STYLES
OPTIONS_DEFAULT=STYLES
STYLES_DESC=	Style formatted output/tables via Pygments

STYLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR}

.include <bsd.port.mk>
