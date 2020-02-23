# Created by: Rafal Lesniak <fbsd@grid.einherjar.de>
# $FreeBSD$

PORTNAME=	idnkit-python
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://jprs.co.jp/idn/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@grid.einherjar.de
COMMENT=	Python bindings for Internationalized Domain Name toolkit 2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libidnkitlite.so:dns/idnkit2

USES=		python:2.7 tar:bzip2
USE_PYTHON=	distutils autoplist

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
