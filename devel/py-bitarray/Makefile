# Created by: Sofian Brabez <sbrabez@gmail.com>

PORTNAME=	bitarray
PORTVERSION=	2.1.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Efficient arrays of booleans

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+

USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	ilanschnell
GH_PROJECT=	bitarray

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	CHANGE_LOG README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bitarray/_bitarray*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bitarray/_util*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

do-test:
	${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} -c "import ${PORTNAME}; ${PORTNAME}.test()"

.include <bsd.port.mk>
