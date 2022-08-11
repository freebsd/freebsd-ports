PORTNAME=	frictionless
PORTVERSION=	4.40.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework to describe, extract, validate, and transform tabular data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=3.0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marko>=1.0:textproc/py-marko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}petl>=1.6:textproc/py-petl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=1.2:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.4:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simpleeval>=0.9.11:devel/py-simpleeval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringcase>=1.2:devel/py-stringcase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tableschema-to-template>=0.0.12:textproc/py-tableschema-to-template@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.8.9:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.4.1:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validators>=0.18:devel/py-validators@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BIGQUERY CKAN EXCEL GSHEETS HTML JSON PANDAS S3 SERVER SQL
BIGQUERY_DESC=	BigQuery support
CKAN_DESC=	CKAN API support
EXCEL_DESC=	Excel file support
GSHEETS_DESC=	Google Sheets support
HTML_DESC=	HTML file support
JSON_DESC=	JSON file support
PANDAS_DESC=	Pandas support
S3_DESC=	AWS S3 support
SERVER_DESC=	API support
SQL_DESC=	SQL databases support

BIGQUERY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.12.1:www/py-google-api-python-client@${PY_FLAVOR}
CKAN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ckanapi>=4.3:devel/py-ckanapi@${PY_FLAVOR}
EXCEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0:textproc/py-openpyxl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tableschema-to-template>=0.0.12:textproc/py-tableschema-to-template@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlrd>=1.2:textproc/py-xlrd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlwt>=1.2:textproc/py-xlwt@${PY_FLAVOR}
GSHEETS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygsheets>=2.0:www/py-pygsheets@${PY_FLAVOR}
HTML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyquery>=1.4:devel/py-pyquery@${PY_FLAVOR}
JSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ijson>=3.0:devel/py-ijson@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}jsonlines>=1.2:devel/py-jsonlines@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=1.0:math/py-pandas@${PY_FLAVOR}
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>=1.9:www/py-boto3@${PY_FLAVOR}
SERVER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=1.1:www/py-flask@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}gunicorn>=20.0:www/py-gunicorn@${PY_FLAVOR}
SQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.3:databases/py-sqlalchemy14@${PY_FLAVOR}

.include <bsd.port.mk>
