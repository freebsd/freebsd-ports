PORTNAME=	poetry-plugin-bundle
PORTVERSION=	1.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	poetry_plugin_bundle-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Poetry plugin to bundle projects into various formats
WWW=		https://github.com/python-poetry/poetry-plugin-bundle

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry>=2.1.0<3.0.0:devel/py-poetry@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
