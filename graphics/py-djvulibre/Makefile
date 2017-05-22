# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	python-djvulibre
PORTVERSION=	0.8
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Python support for the DjVu image format

LICENSE=	GPLv2

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre

USES=		python:2 pkgconfig
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e "s|'python'|'${PYTHON_CMD}'|g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
