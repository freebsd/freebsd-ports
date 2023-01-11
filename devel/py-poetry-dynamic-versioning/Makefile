PORTNAME=	poetry-dynamic-versioning
PORTVERSION=	0.19.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Plugin for Poetry to enable dynamic versioning based on VCS tags
WWW=		https://github.com/mtkennerly/poetry-dynamic-versioning

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dunamai>=1.12.0<2.0.0:devel/py-dunamai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.1<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.4:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
