PORTNAME=	dacite
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple creation of data classes from dictionaries
WWW=		https://github.com/konradhalas/dacite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	konradhalas

# tests as of 1.9.2: 199 passed, 0 failed (12.11s)

.include <bsd.port.mk>
