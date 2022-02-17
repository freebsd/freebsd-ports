# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	pycoin
PORTVERSION=	0.92.20220213
CATEGORIES=	finance
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utilities for Bitcoin and altcoin addresses/transaction manipulation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	block keychain

NO_ARCH=	yes

.include <bsd.port.mk>
