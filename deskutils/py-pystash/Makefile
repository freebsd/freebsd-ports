# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pystash
PORTVERSION=	0.0.14
#PORTREVISION=	0
CATEGORIES=	deskutils
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Save your code snippets in the cloud from the command line

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}args>=0.1.0:devel/py-args \
		${PYTHON_PKGNAMEPREFIX}clint>=0.3.7:devel/py-clint \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}xerox>=0.3.1:devel/py-xerox

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
