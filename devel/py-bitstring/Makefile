# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	bitstring
PORTVERSION=	3.1.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Simple construction, analysis, and modification of binary data

LICENSE=	MIT

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	PKG-INFO README.rst release_notes.txt

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

regression-test: extract
	@(cd ${WRKSRC}/test && ${PYTHON_CMD} -c 'import unittest, test_${PORTNAME}; unittest.main(test_${PORTNAME})')

.include <bsd.port.mk>
