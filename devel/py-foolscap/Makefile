# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foolscap
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	http://foolscap.lothar.com/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	RPC protocol for Twisted Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python twisted
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
