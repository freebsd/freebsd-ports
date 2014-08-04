# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedNames
PORTVERSION=	14.0.0
CATEGORIES=	dns devel python
MASTER_SITES=	http://twistedmatrix.com/Releases/Names/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedNames-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	DNS protocol implementation with client and server

LICENSE=	MIT

USE_PYTHON=	2
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes
USES=		tar:bzip2 twisted

.include <bsd.port.mk>
