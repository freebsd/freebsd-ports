# Created by: Sofian Brabez <sbrabez@gmail.com>

PORTNAME=	bitarray
PORTVERSION=	1.9.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Efficient arrays of booleans

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+

USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	ilanschnell
GH_PROJECT=	bitarray

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	CHANGE_LOG README.rst TODO changelog.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

do-test:
	${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} -c "import ${PORTNAME}; ${PORTNAME}.test()"

.include <bsd.port.mk>
