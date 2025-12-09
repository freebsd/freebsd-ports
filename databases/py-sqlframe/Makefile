PORTNAME=	sqlframe
PORTVERSION=	3.43.8
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Turn PySpark Into a Universal DataFrame API
WWW=		https://sqlframe.readthedocs.io/en/stable/ \
		https://github.com/eakmanrq/sqlframe

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}more-itertools>=0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0<4:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlglot>=24.0.0<27.30:databases/py-sqlglot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	BIGQUERY DUCKDB OPENAI PANDAS POSTGRES REDSHIFT
BIGQUERY_DESC=	BigQuery support
DUCKDB_DESC=	DuckDB support
DUCKDB_IMPLIES=	PANDAS
OPENAI_DESC=	OpenAI support
PANDAS_DESC=	Pandas support
POSTGRES_DESC=	PostgreSQL support
REDSHIFT_DESC=	Amazon Redshift support

BIGQUERY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-bigquery>=3<4:www/py-google-cloud-bigquery@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}google-cloud-bigquery-storage>=2<3:www/py-google-cloud-bigquery-storage@${PY_FLAVOR}
DUCKDB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}duckdb>=1.2<1.5:databases/py-duckdb@${PY_FLAVOR}
OPENAI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openai>=1.30<3:misc/py-openai@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=2,1<3,1:math/py-pandas@${PY_FLAVOR}
POSTGRES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8<3:databases/py-psycopg2@${PY_FLAVOR}
REDSHIFT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redshift-connector>=2.1.1<2.2.0:databases/py-redshift-connector@${PY_FLAVOR}

.include <bsd.port.mk>
