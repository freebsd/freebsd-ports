PORTNAME=	nbformat
PORTVERSION=	5.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Jupyter Notebook format
WWW=		https://jupyter.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastjsonschema>=0:devel/py-fastjsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.1:devel/py-traitlets@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}check-manifest>=0:devel/py-check-manifest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep440>=0:devel/py-pep440@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>=0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
