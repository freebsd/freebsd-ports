PORTNAME=	smmap
PORTVERSION=	5.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sliding-window memory map manager
WWW=		https://smmap.readthedocs.io/en/latest/ \
		https://github.com/gitpython-developers/smmap

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

PORTSCOUT=	skipv:6.0.0

.include <bsd.port.mk>
