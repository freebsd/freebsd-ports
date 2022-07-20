PORTNAME=	bitstring
PORTVERSION=	3.1.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Simple construction, analysis, and modification of binary data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	PKG-INFO README.rst release_notes.txt

OPTIONS_DEFINE=	DOCS
NO_ARCH=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC}/test && ${PYTHON_CMD} -c 'import unittest, test_${PORTNAME}; unittest.main(test_${PORTNAME})')

.include <bsd.port.mk>
