# Created by: Daniel O'Connor
# $FreeBSD$

PORTNAME=	rrdtool
DISTVERSION=	0.1.15
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
# Bindings name is different from https://pypi.org/project/rrdtool/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	darius@dons.net.au
COMMENT=	Python interface to RRDTool, the graphing and logging utility

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librrd.so:databases/rrdtool

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rrdtool*.so

.include <bsd.port.mk>
