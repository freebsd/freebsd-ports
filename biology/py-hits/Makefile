# $FreeBSD$

PORTNAME=	hits
PORTVERSION=	0.1
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities for processing high-throughput sequencing experiments

LICENSE=	GPLv3

USES=		python:3.6+
USE_PYTHON=	distutils cython autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/hits/*.so

.include <bsd.port.mk>
