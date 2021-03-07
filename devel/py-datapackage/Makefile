# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	datapackage
PORTVERSION=	1.15.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities to work with Data Packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=3.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>=1.10:devel/py-jsonpointer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.8:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tableschema>=1.12.1:databases/py-tableschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulator>=1.29:devel/py-tabulator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicodecsv>=0.14:devel/py-unicodecsv@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CCHARDET
CCHARDET_DESC=	Character detector support

CCHARDET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cchardet>=2.0:textproc/py-cchardet@${PY_FLAVOR}

.include <bsd.port.mk>
