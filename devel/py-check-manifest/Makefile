# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	check-manifest
PORTVERSION=	0.31
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Check MANIFEST.in in a Python source package for completeness

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

PORTDOCS=	README.rst CHANGES.rst

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
