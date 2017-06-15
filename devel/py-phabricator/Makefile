# Created by: Sofian Brabez <sbz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phabricator
PORTVERSION=	0.7.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Phabricator API Bindings

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes

GH_ACCOUNT=	disqus
GH_PROJECT=	python-${PORTNAME}
GH_TAGNAME=	dac1219

PORTDOCS=	CHANGES LICENSE README.rst

OPTIONS_DEFINE=	DOCS TESTS

TESTS_DESC=		Include test suite requirements
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
