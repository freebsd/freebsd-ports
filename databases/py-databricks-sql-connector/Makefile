PORTNAME=	databricks-sql-connector
PORTVERSION=	4.2.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	databricks_sql_connector-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Databricks SQL Connector for Python
WWW=		https://github.com/databricks/databricks-sql-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lz4>=4.0.2<5:archivers/py-lz4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=3.1.0<4:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0.10<4:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.3,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybreaker>=1.0.0<2:devel/py-pybreaker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0.0<3:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.0<3:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.1<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-kerberos>=0.15.0<0.16:www/py-requests-kerberos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thrift>=0.16.0,1:devel/py-thrift@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26,1:net/py-urllib3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	src/databricks/sql/thrift_api/TCLIService/TCLIService-remote

OPTIONS_DEFINE=	PYARROW
OPTIONS_DEFAULT=PYARROW
PYARROW_DESC=	Apache Arrow support

PYARROW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyarrow>=18.0.0:databases/py-pyarrow@${PY_FLAVOR}

.include <bsd.port.mk>
