# Created by: James Bowman <jamesb-bsd@excamera.com>
# $FreeBSD$

PORTNAME=	openexr
PORTVERSION=	1.2.0
PORTREVISION=	9
CATEGORIES=	graphics python
MASTER_SITES=	http://excamera.com/files/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OpenEXR-${PORTVERSION}

MAINTAINER=	jamesb-bsd@excamera.com
COMMENT=	Python module for ILM's OpenEXR image format and library

LIB_DEPENDS=	libIlmImf.so:graphics/openexr

USES=		compiler:c++11-lang python:2.7
USE_PYTHON=	distutils autoplist

post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
