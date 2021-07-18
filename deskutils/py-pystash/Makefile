# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	pystash
PORTVERSION=	0.0.14
PORTREVISION=	0
CATEGORIES=	deskutils
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Save your code snippets in the cloud from the command line

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}args>=0.1.0:devel/py-args@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}clint>=0.3.7:devel/py-clint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xerox>=0.3.1:devel/py-xerox@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
