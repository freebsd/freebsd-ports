# $FreeBSD$

PORTNAME=	adb
DISTVERSION=	1.1.1-37
DISTVERSIONSUFFIX=	-gfb09de9
PORTREVISION=	1
CATEGORIES=	devel comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Pure-python implementation of ADB and Fastboot protocols

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libusb115>=1.0.16:devel/py-libusb115@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}m2crypto>=0.21.1:security/py-m2crypto@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	python-${PORTNAME}

NO_ARCH=	yes
USES=		python:-2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
