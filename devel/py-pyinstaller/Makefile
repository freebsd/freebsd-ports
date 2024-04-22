PORTNAME=	pyinstaller
DISTVERSION=	6.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hsw@bitmark.com
COMMENT=	Program to create standalone executables from Python scripts
WWW=		https://www.pyinstaller.org/

LICENSE=	APACHE20 GPLv2 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}altgraph>0:math/py-altgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-autodoc-typehints>0:textproc/py-sphinx-autodoc-typehints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-issues>0:textproc/py-sphinx-issues@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-towncrier>0:textproc/py-sphinxcontrib-towncrier@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}altgraph>0:math/py-altgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinstaller-hooks-contrib>0:devel/py-pyinstaller-hooks-contrib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}execnet>0:sysutils/py-execnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	share/man/man1/pyi-makespec.1.gz \
		share/man/man1/pyinstaller.1.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-build:
	cd ${WRKSRC}/bootloader && \
		${PYTHON_CMD} waf all

do-build-DOCS-on:
	(cd ${WRKSRC}/doc && \
		${SETENV} sphinx-build-${PYTHON_VER} -b html . _build/html)

post-build:
	(cd ${WRKSRC}/doc && \
		${SETENV} sphinx-build-${PYTHON_VER} -b man . _build/man)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/_build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo -not -regex ^./.doctrees.* -not -regex ^./_sources.*")

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/_build/man/*.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
