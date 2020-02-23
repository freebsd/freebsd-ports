# Created by: D'Arcy J.M. Cain <darcy@druid.net>
# $FreeBSD$

PORTNAME=	generate
PORTVERSION=	2.8
CATEGORIES=	devel python
MASTER_SITES=	http://druid.net/darcy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	darcy@druid.net
COMMENT=	Python module to implement generate

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7 tar:tgz
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/generate.so

.include <bsd.port.mk>
