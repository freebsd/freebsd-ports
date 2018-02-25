# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	testtools
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensions to the Python standard library unit testing framework

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.11:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}extras>=1.0.0:devel/py-extras@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traceback2>=0:devel/py-traceback2@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

PORTDOCS=	api.rst for-framework-folk.rst for-test-authors.rst hacking.rst \
		index.rst overview.rst twisted-support.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
