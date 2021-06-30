# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frictionless
PORTVERSION=	4.12.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework to describe, extract, validate, and transform tabular data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=3.0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}petl>=1.6:textproc/py-petl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=1.2:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.4:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simpleeval>=0.9:devel/py-simpleeval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringcase>=1.2:devel/py-stringcase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.3:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validators>=0.18:devel/py-validators@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
