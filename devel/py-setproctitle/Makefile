PORTNAME=	setproctitle
PORTVERSION=	1.3.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python module to customize the process title
WWW=		https://pypi.org/project/setproctitle/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		python
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	HISTORY.rst README.rst

OPTIONS_DEFINE=	DOCS

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

TESTING_UNSAFE=	ImportError: attempted relative import with no known parent package

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*setproctitle*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC}/tests && ${PYTHON_CMD} ${WRKSRC}/tests/setproctitle_test.py

.include <bsd.port.mk>
