PORTNAME=	toolz
DISTVERSION=	0.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functional standard library for Python
WWW=		https://github.com/pytoolz/toolz

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	distutils autoplist pytest # 2 test fail, see https://github.com/pytoolz/toolz/issues/573

NO_ARCH=	yes

# 'from tlz import curry' fails, see https://github.com/pytoolz/toolz/issues/573

.include <bsd.port.mk>
