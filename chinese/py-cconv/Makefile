# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cconv
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	python-
CATEGORIES=	chinese converters python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper for chinese/cconv

LICENSE=	GPLv2

LIB_DEPENDS=	libcconv.so:${PORTSDIR}/chinese/cconv

USE_PYTHON=	autoplist concurrent distutils
USES=		localbase python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cconv.so

.include <bsd.port.mk>
