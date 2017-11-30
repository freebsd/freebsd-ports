# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	python-lzo
PORTVERSION=	1.11
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Python bindings for the LZO data compression library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		python
USE_PYTHON=	autoplist distutils
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/lzo

.include <bsd.port.mk>
