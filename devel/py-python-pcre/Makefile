# $FreeBSD$

PORTNAME=	python-pcre
DISTVERSION=	0.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Python PCRE bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python${PYTHON_VER}/site-packages/_pcre*.so

.include <bsd.port.mk>
