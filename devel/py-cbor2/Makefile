# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cbor2
PORTVERSION=	4.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Pure Python CBOR (de)serializer with extensive tag support

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist concurrent distutils

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm

#post-install:
#	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cbor/_cbor.so

.include <bsd.port.mk>
