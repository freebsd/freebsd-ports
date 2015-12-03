# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	python-obelisk
PORTVERSION=	0.1.3
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Python native client for the obelisk blockchain server

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twistedCore>0:${PORTSDIR}/devel/py-twistedCore \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:${PORTSDIR}/security/py-ecdsa \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=14.5.0:${PORTSDIR}/net/py-pyzmq

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
