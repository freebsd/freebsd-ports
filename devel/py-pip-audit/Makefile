PORTNAME=	pip-audit
PORTVERSION=	2.9.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/pypa/pip-audit/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pip_audit-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for scanning Python environments for known vulnerabilities
WWW=		https://github.com/pypa/pip-audit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.13.0:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>=5<12:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-api>=0.0.28:devel/py-pip-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-requirements-parser>=32.0.0:devel/py-pip-requirements-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.2.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.4:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10:textproc/py-toml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
