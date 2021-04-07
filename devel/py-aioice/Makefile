PORTNAME=	aioice
PORTVERSION=	0.7.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Interactive Connectivity Establishment (RFC 5245) in Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.4:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython2>=0:dns/py-dnspython2@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
