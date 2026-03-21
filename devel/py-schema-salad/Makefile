PORTNAME=	schema-salad
PORTVERSION=	8.9.20251102115403
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	schema_salad-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schema Annotations for Linked Avro Data (SALAD)
WWW=		https://schema-salad.readthedocs.io/ \
		https://github.com/common-workflow-language/schema_salad

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.12.9:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=3.0:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.2.2:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17.6:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent

NO_ARCH=	yes

post-extract: # pyproject.toml is messed up - replace if with a minimal one
	@${RM} ${WRKSRC}/pyproject.toml
	@${ECHO} "[build-system]" > ${WRKSRC}/pyproject.toml
	@${ECHO} 'requires = ["setuptools", "setuptools_scm[toml]>=8.0.4"]' >> ${WRKSRC}/pyproject.toml
	@${ECHO} 'build-backend = "setuptools.build_meta"' >> ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
