# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tabulator
PORTVERSION=	1.53.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Consistent interface for stream reading and writing tabular data (csv/xls/json/etc)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.9:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ijson>=3.0.3:devel/py-ijson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonlines>=1.1:devel/py-jsonlines@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}linear-tsv>=1.0:devel/py-linear-tsv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=2.6:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.8:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy13>=0.9.6:databases/py-sqlalchemy13@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicodecsv>=0.14:devel/py-unicodecsv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=1.0:textproc/py-xlrd@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CCHARDET DATAPACKAGE
CCHARDET_DESC=		Character encoding detection via cchardet
DATAPACKAGE_DESC=	Data Package support

CCHARDET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cchardet>=2.0:textproc/py-cchardet@${PY_FLAVOR}
DATAPACKAGE_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}datapackage>=1.12:devel/py-datapackage@${PY_FLAVOR}

.include <bsd.port.mk>
