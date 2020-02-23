# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	cjson
PORTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-cjson-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Fast JSON encoder/decoder for Python

LICENSE=	LGPL20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cjson.so

.include <bsd.port.mk>
