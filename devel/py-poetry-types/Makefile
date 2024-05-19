PORTNAME=	poetry-types
PORTVERSION=	0.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	poetry_types-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Poetry plugin that adds/removes type stubs as dependencies
WWW=		https://github.com/jvllmr/poetry-types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0<25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=1.6<2:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0<1.0:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
