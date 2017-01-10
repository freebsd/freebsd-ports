# $FreeBSD$

PORTNAME=	adb
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel comms python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Pure-python implementation of ADB and Fastboot protocols

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libusb1>0:devel/py-libusb1 \
		${PYTHON_PKGNAMEPREFIX}python-gflags>0:devel/py-python-gflags \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:security/py-m2crypto

NO_ARCH=	yes
USES=		python:-2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
