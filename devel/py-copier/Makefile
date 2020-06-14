# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	copier
PORTVERSION=	3.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for rendering project templates

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.0<1.0.0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.0<3.0.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.1<21.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.7.0<0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plumbum>=1.6.0<2.0.0:sysutils/py-plumbum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3<6.0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml-include>=1.2<2.0:devel/py-pyyaml-include@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2020.2.20<2021.0.0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=2.10.0<3.0.0:devel/py-semver@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
