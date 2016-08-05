# $FreeBSD$

PORTNAME=	horoscopegenerator
PORTVERSION=	0.1.8
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
DISTNAME=	${PORTNAME:S/h/H/:S/g/G/}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Generate horoscopes using context-free grammar

LICENSE=	MIT

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}nltk>0:textproc/py-nltk

.include <bsd.port.mk>
