# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	oursql
PORTVERSION=	0.9.3.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MySQL bindings for python

LICENSE=	BSD2CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		compiler:c11 mysql python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/oursql.so

.include <bsd.port.mk>
