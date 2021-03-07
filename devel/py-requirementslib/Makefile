# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requirementslib
PORTVERSION=	1.5.16
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for converting between pip-style and pipfile requirements

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}invoke>=0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parver>=0:devel/py-parver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vistir>=0.3.1:devel/py-vistir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=19.2:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cached-property>=0:devel/py-cached-property@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distlib>=0.2.8:devel/py-distlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orderedmultidict>=0:devel/py-orderedmultidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=19.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep517>=0.5.0:devel/py-pep517@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-shims>=0.5.2:devel/py-pip-shims@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plette>=0:devel/py-plette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.5.3:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vistir>=0.3.1:devel/py-vistir@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
