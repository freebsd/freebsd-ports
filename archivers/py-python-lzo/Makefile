# Created by: Yuri Victorovich <yuri@rawbw.com>

PORTNAME=	python-lzo
DISTVERSION=	1.14
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the LZO data compression library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		localbase python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
