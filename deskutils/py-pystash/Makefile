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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}args>=0.1.0:${PORTSDIR}/devel/py-args \
		${PYTHON_PKGNAMEPREFIX}clint>=0.3.7:${PORTSDIR}/devel/py-clint \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}xerox>=0.3.1:${PORTSDIR}/devel/py-xerox

PYDISTUTILS_AUTOPLIST=	yes

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
