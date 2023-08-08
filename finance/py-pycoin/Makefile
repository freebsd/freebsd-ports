PORTNAME=	pycoin
PORTVERSION=	0.92.20230326
CATEGORIES=	finance
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utilities for Bitcoin and altcoin addresses/transaction manipulation
WWW=		https://github.com/richardkiss/pycoin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	block keychain

NO_ARCH=	yes

.include <bsd.port.mk>
