# $FreeBSD$

PORTNAME=	gast
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AST that abstracts the underlying Python version

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astunparse>=0:devel/py-astunparse@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
