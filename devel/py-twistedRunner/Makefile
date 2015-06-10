# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedRunner
PORTVERSION=	15.2.1
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/Releases/Runner/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedRunner-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Runner has process management, including an inetd replacement

LICENSE=	MIT

USE_PYTHON=	autoplist distutils
USES=		python:2 tar:bzip2 twisted

.include <bsd.port.mk>
