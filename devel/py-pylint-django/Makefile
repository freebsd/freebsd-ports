PORTNAME=	pylint-django
PORTVERSION=	2.6.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pylint plugin to understand the Django web framework
WWW=		https://github.com/pylint-dev/pylint-django

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylint-plugin-utils>=0.8:devel/py-pylint-plugin-utils@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=3.0<4:devel/pylint@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DJANGO
DJANGO_DESC=	Django support

DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.2:www/py-django42@${PY_FLAVOR}

.include <bsd.port.mk>
