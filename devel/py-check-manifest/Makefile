# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	checkmanifest
PORTVERSION=	0.22
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	check-manifest-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Check MANIFEST.in in a Python source package for completeness

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils autoplist concurrent

PORTDOCS=	README.rst CHANGES.rst

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
