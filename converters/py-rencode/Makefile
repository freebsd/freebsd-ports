# $FreeBSD$

PORTNAME=	rencode
PORTVERSION=	1.0.6
CATEGORIES=	converters devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	R-encoding and r-decoding implementation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rencode/_rencode.so

.include <bsd.port.mk>
