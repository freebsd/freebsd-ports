# Created by: ijliao
# $FreeBSD$

PORTNAME=	ciphon
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	SF/pythonsiphon/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Module for python that adds cpan-like functionality

LICENSE=	BSD2CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7
USE_PYTHON=	distutils

post-install:
	@${MV} -f ${STAGEDIR}${PREFIX}/bin/ciphon.py ${STAGEDIR}${PREFIX}/bin/ciphon

.include <bsd.port.mk>
