# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedFlow
PORTVERSION=	8.2.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://tmrc.mit.edu/mirror/twisted/Flow/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedFlow-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Generator based asynchronous result flows

LICENSE=	MIT

DEPRECATED=	Use devel/py-twisted instead
EXPIRATION_DATE=2017-09-30

WRKSRC=		${WRKDIR}/TwistedFlow-${PORTVERSION}

USES=		python tar:bzip2 twisted
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
