PORTNAME=	sqlglotc
PORTVERSION=	30.8.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	sqlglot-${PORTVERSION}${EXTRACT_SUFX} \
		sqlglotc-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	mypyc-compiled extensions for SQLGlot
WWW=		https://github.com/tobymao/sqlglot/tree/main/sqlglotc \
		https://github.com/tobymao/sqlglot

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlglot-mypy>=1.20.0.post6:databases/py-sqlglot-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-python-dateutil>=0:devel/py-types-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-patch:
	@${LN} -s sqlglot-${PORTVERSION}/sqlglot ${WRKDIR}/sqlglot

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
