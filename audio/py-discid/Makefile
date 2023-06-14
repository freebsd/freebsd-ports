PORTNAME=	discid
PORTVERSION=	1.2.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python libdiscid bindings
WWW=		https://python-discid.readthedocs.io/en/latest/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libdiscid.so:audio/libdiscid

USES=		python
USE_PYTHON=	autoplist distutils unittest

NO_ARCH=	yes

.include <bsd.port.mk>
