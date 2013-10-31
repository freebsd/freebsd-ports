# Created by: James Bowman <jamesb-bsd@excamera.com>
# $FreeBSD$

PORTNAME=	openexr
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://excamera.com/files/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OpenEXR-${PORTVERSION}

MAINTAINER=	jamesb-bsd@excamera.com
COMMENT=	Python module for ILM's OpenEXR image format and library

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR

NO_STAGE=	yes
post-extract:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/setup.py

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	OpenEXR
MASTER_SITE_SUBDIR=source/O/OpenEXR

.include <bsd.port.mk>
