# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	check-manifest
PORTVERSION=	0.36
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to check the completeness of MANIFEST.in for Python packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${FLAVOR}

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

PORTDOCS=	CHANGES.rst README.rst

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
