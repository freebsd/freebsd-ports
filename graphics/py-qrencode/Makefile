# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qrencode
PORTVERSION=	1.2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Simple wrapper for the C qrencode library

LICENSE=	MIT

BUILD_DEPENDS=	libqrencode>0:graphics/libqrencode
RUN_DEPENDS=	libqrencode>0:graphics/libqrencode
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

CFLAGS+=	-I${PREFIX}/include

NO_ARCH_IGNORE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
