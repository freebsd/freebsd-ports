PORTNAME=	discid
PORTVERSION=	1.2.0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python libdiscid bindings

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libdiscid.so:audio/libdiscid

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

TEST_TARGET=	test
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYSETUP}

.include <bsd.port.mk>
