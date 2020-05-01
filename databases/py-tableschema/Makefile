# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tableschema
PORTVERSION=	1.17.0
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility library for working with Table Schema

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=3.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.4:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.5.4:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.1.0:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulator>=1.29:devel/py-tabulator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicodecsv>=0.14:devel/py-unicodecsv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
