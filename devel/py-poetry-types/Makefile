PORTNAME=	poetry-types
PORTVERSION=	0.6.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	poetry_types-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Poetry plugin that adds/removes type stubs as dependencies
WWW=		https://github.com/jvllmr/poetry-types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.4.1:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>=1.2.5:devel/py-dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=26.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=2.4.1<3.0:devel/py-poetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.15.0:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
