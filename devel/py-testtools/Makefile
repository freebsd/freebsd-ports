PORTNAME=	testtools
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensions to the Python standard library unit testing framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.11:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}extras>=1.0.0:devel/py-extras@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=0.11:devel/py-pbr@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTDOCS=	api.rst for-framework-folk.rst for-test-authors.rst hacking.rst \
		index.rst overview.rst twisted-support.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
