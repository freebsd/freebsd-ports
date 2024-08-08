PORTNAME=	bitstring
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Simple construction, analysis, and modification of binary data
WWW=		https://pypi.org/project/bitstring/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent pep517

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	PKG-INFO README.md release_notes.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bitarray>=2.8.0:devel/py-bitarray@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS
NO_ARCH=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC}/tests && ${PYTHON_CMD} -c 'import unittest, test_${PORTNAME}; unittest.main(test_${PORTNAME})')

.include <bsd.port.mk>
