# $FreeBSD$

PORTNAME=	python-pcre
PORTVERSION=	0.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	Python PCRE bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pcre>=6.0:devel/pcre
LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		python:2
USE_PYTHON=	autoplist distutils

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
