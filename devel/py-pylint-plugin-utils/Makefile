PORTNAME=	pylint-plugin-utils
PORTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylint_plugin_utils-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities and helpers for writing Pylint plugins
WWW=		https://github.com/pylint-dev/pylint-plugin-utils

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	pylint${PYTHON_PKGNAMESUFFIX}>=1.7:devel/pylint@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
