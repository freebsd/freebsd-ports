# $FreeBSD$

PORTNAME=	music21
DISTVERSION=	5.7.2
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolkit for computer-aided musical analysis

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
