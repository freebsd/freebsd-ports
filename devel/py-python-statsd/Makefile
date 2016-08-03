# $FreeBSD$

PORTNAME=	python-statsd
PORTVERSION=	2.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fax@nohik.ee
COMMENT=	Statsd is a client for Etsy's node-js statsd server

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
