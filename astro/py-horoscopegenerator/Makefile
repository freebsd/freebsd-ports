# $FreeBSD$

PORTNAME=	HoroscopeGenerator
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate horoscopes using context-free grammar

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nltk>0:textproc/py-nltk@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
