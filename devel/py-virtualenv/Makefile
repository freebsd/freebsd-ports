PORTNAME=	virtualenv
PORTVERSION=	16.7.5
PORTREVISION=	0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for creating isolated Python environments

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.8.0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}towncrier>0:textproc/py-towncrier@${PY_FLAVOR}
DOCS_BINARY_ALIAS=	towncrier=towncrier-${PYTHON_VER}
DOCS_PORTDOCS=	*
DOCS_VARS=	PYDISTUTILS_BUILD_TARGET="build build_sphinx"

# Required by towncrier/click when Python < 3.7
# see https://click.palletsprojects.com/en/7.x/python3/
# Documentation is in English, so...
MAKE_ENV=	LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8

GH_ACCOUNT=	pypa

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PYDISTUTILS_BUILDARGS=	-c ${WRKSRC}/docs

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -or -name objects.inv")

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
