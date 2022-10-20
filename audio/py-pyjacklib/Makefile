PORTNAME=	py-pyjacklib
DISTVERSIONPREFIX=	v
DISTVERSION=		0.1.1
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Python bindings for the Jack library
WWW=		https://github.com/jackaudio/pyjacklib

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libjack.so:audio/jack

USES=		localbase python:3.6+
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	jackaudio
GH_PROJECT=	pyjacklib

.include <bsd.port.mk>
