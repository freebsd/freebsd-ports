PORTNAME=	pymssql
DISTVERSION=	2.4.5
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cweimann@gmail.com
COMMENT=	DB-API interface to Microsoft SQL Server for Python
WWW=		https://github.com/pymssql/pymssql

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=24.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.36.2:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libsybdb.so:databases/freetds

USES=		python
USE_PYTHON=	autoplist cython pep517

# Link the system FreeTDS dynamically; do not pull in krb5/OpenSSL directly
# (FreeTDS already links what it needs).
MAKE_ENV=	LINK_FREETDS_STATICALLY=NO \
		LINK_KRB5=NO \
		LINK_OPENSSL=NO \
		PYMSSQL_FREETDS=${LOCALBASE} \
		SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

NO_TEST=	yes

post-patch:
# standard-distutils is not ported (setuptools ships a distutils shim) and
# tomli is not used by setup.py; drop them so the no-isolation build passes.
# Upstream pins setuptools>80 in pyproject.toml and setup.cfg; ports ships 63.x
# and it builds fine, so relax both.
	@${REINPLACE_CMD} -e '/"tomli"/d' -e '/standard-distutils/d' \
		-e 's/setuptools>80\.0/setuptools>=63/' \
		${WRKSRC}/pyproject.toml
	@${REINPLACE_CMD} -e 's/setuptools>80\.0/setuptools>=63/' \
		${WRKSRC}/setup.cfg

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/pymssql -name '*.so' \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
