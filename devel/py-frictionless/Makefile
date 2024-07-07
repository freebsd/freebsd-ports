PORTNAME=	frictionless
PORTVERSION=	5.17.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework to describe, extract, validate, and transform tabular data
WWW=		https://github.com/frictionlessdata/frictionless-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=22.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=4.2:devel/py-humanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.20:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marko>=1.0:textproc/py-marko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}petl>=1.6:textproc/py-petl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=1.2:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.4:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simpleeval>=0.9.11:devel/py-simpleeval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stringcase>=1.2:devel/py-stringcase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.8.9:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}validators>=0.18:devel/py-validators@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	AWS BIGQUERY CKAN DATASETTE EXCEL GITHUB GSHEETS HTML JSON MYSQL PANDAS PARQUET POSTGRESQL SQL VISIDATA WKT
AWS_DESC=	AWS S3 support
BIGQUERY_DESC=	BigQuery support
CKAN_DESC=	CKAN API support
DATASETTE_DESC=	Datasette support
EXCEL_DESC=	Excel file support
GITHUB_DESC=	GitHub support
GSHEETS_DESC=	Google Sheets support
HTML_DESC=	HTML file support
JSON_DESC=	JSON file support
PANDAS_DESC=	Pandas support
PARQUET_DESC=	Parquet file format support
POSTGRESQL_DESC=PostgreSQL database support
SQL_DESC=	SQL databases support
VISIDATA_DESC=	VisiData support
WKT_DESC=	Well-known text (WKT) support

AWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.9:www/py-boto3@${PY_FLAVOR}
BIGQUERY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.12.1:www/py-google-api-python-client@${PY_FLAVOR}
CKAN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}frictionless-ckan-mapper>=1.0:devel/py-frictionless-ckan-mapper@${PY_FLAVOR}
DATASETTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}datasette>=0.64.2:devel/py-datasette@${PY_FLAVOR}
EXCEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0:textproc/py-openpyxl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tableschema-to-template>=0.0:textproc/py-tableschema-to-template@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlrd>=1.2:textproc/py-xlrd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlwt>=1.2:textproc/py-xlwt@${PY_FLAVOR}
GITHUB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyGithub>=1.50:devel/py-PyGithub@${PY_FLAVOR}
GSHEETS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygsheets>=2.0:www/py-pygsheets@${PY_FLAVOR}
HTML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyquery>=1.4:devel/py-pyquery@${PY_FLAVOR}
JSON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ijson>=3.0:devel/py-ijson@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}jsonlines>=1.2:devel/py-jsonlines@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymysql>=1.0:databases/py-pymysql@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4:databases/py-sqlalchemy20@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=1.0,1:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyarrow>=14.0:databases/py-pyarrow@${PY_FLAVOR}
PARQUET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastparquet>=0.8:databases/py-fastparquet@${PY_FLAVOR}
POSTGRESQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg>=3.0:databases/py-psycopg@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4:databases/py-sqlalchemy20@${PY_FLAVOR}
SQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4:databases/py-sqlalchemy20@${PY_FLAVOR}
VISIDATA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}visidata>=2.10:devel/py-visidata@${PY_FLAVOR}
WKT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grako>=3.99:textproc/py-grako@${PY_FLAVOR}

.include <bsd.port.mk>
