# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	watchfiles
PORTVERSION=	0.14.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, modern and high performance file watching and code reload in python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.0.0<4:devel/py-anyio@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	SKIP_RUST_EXTENSION=1
NO_ARCH=	yes

.include <bsd.port.mk>
