# $FreeBSD$

PORTNAME=	deepdiff
DISTVERSION=	4.0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deep difference and search of any Python object/data

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpickle>0:devel/py-jsonpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordered-set>0:devel/py-ordered-set@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
