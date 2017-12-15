# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	gitdb
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Pure Python git object database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}smmap>=0.8.5:devel/py-smmap@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/gitdb/_perf.so

.include <bsd.port.mk>
