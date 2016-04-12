# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	botocore
PORTVERSION=	1.4.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Low-level, core functionality of boto 3

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.7.1:devel/py-jmespath \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
