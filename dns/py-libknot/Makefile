PORTNAME=	libknot
DISTVERSION=	${KNOT_VERSION}
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@dns.company
COMMENT=	Python API using knot.sock to interact with the Knot DNS daemon
WWW=		https://gitlab.nic.cz/knot/knot-dns/-/tree/master/python/libknot

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
LIB_DEPENDS=	libknot.so:dns/knot3

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include "${.CURDIR}/../knot3/knotdns.mk"
.include <bsd.port.mk>
