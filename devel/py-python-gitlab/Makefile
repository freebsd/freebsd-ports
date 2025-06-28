PORTNAME=	python-gitlab
DISTVERSION=	6.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSIONFULL}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Interact with GitLab API
WWW=		https://github.com/python-gitlab/python-gitlab

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=1.0.0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-console-scripts>0:devel/py-pytest-console-scripts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>0:net/py-trio@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ARGS=	tests/unit

NO_ARCH=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		AUTOCOMPLETE DOCS GRAPHQL YAML
OPTIONS_DEFAULT=	AUTOCOMPLETE GRAPHQL YAML
OPTIONS_EXCLUDE=	DOCS

AUTOCOMPLETE_DESC=	Autocompletion via argcomplete
GRAPHQL_DESC=		GraphQL support
YAML_DESC=		YAML output

AUTOCOMPLETE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.10.0<4:devel/py-argcomplete@${PY_FLAVOR}

DOCS_BROKEN=		Require py-sphinx >= 8: cannot import name '_ConfigRebuild' from 'sphinx.config'
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}furo>0:textproc/py-furo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}myst-parser>0:textproc/py-myst-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.10.1:www/py-requests-toolbelt@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.25.0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=4.3.1,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-autoprogram>0:textproc/py-sphinxcontrib-autoprogram@${PY_FLAVOR}
DOCS_PORTDOCS=		*

GRAPHQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gql>=3.5<4:devel/py-gql@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR}

GRAPHQL_TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}respx>0:www/py-respx@${PY_FLAVOR}

YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=5.2:devel/py-pyyaml@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}/etc|g' ${WRKSRC}/gitlab/config.py

do-build-DOCS-on::
	(cd ${WRKSRC} && sphinx-build -j auto -n -W --keep-going -b html docs build/sphinx/html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
	${RM} -r .doctrees && \
	${RM} .buildinfo objects.inv && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
