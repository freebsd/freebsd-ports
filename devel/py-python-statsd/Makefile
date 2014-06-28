# $FreeBSD$

PORTNAME=	python-statsd
PORTVERSION=	1.6.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fax@nohik.ee
COMMENT=	Statsd is a client for Etsy's node-js statsd server

LICENSE=	BSD3CLAUSE

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
