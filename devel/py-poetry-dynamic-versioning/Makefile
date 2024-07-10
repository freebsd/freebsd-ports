PORTNAME=	poetry-dynamic-versioning
PORTVERSION=	1.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	poetry_dynamic_versioning-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Plugin for Poetry to enable dynamic versioning based on VCS tags
WWW=		https://github.com/mtkennerly/poetry-dynamic-versioning

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dunamai>=1.21.0<2:devel/py-dunamai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.1<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.4:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
