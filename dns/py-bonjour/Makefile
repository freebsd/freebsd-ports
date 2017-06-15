# $FreeBSD$

PORTNAME=	pybonjour
PORTVERSION=	1.1.1
CATEGORIES=	dns python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

LIB_DEPENDS=	libdns_sd.so.1:net/mDNSResponder

LICENSE=	MIT

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Unfetchable for more than six months (google code has gone away)
EXPIRATION_DATE=	2017-04-30

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	depl0y
GH_PROJECT=	pybonjour-python3
GH_TAGNAME=	2c8283f

NO_ARCH=	yes

.include <bsd.port.mk>
