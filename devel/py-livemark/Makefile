PORTNAME=	livemark
PORTVERSION=	0.110.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data presentation framework for Python
WWW=		https://livemark.frictionlessdata.io/ \
		https://github.com/frictionlessdata/livemark

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=22.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cached-property>=1.5:devel/py-cached-property@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepmerge>=0.3:devel/py-deepmerge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docstring-parser>=0.10:textproc/py-docstring-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frictionless>=4.0:devel/py-frictionless@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}giturlparse>=0.10:devel/py-giturlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema417>=2.5:devel/py-jsonschema417@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}livereload>=2.6:www/py-livereload@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marko>=1.0:textproc/py-marko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyquery>=1.0:devel/py-pyquery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.3:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
