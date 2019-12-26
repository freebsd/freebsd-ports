# $FreeBSD$

PORTNAME=	openark-kit
PORTVERSION=	196
CATEGORIES=	databases
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/openarkkit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common utilities for MySQL

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
