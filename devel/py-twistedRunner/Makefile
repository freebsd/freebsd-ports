# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedRunner
PORTVERSION=	15.2.1
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/Releases/Runner/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedRunner-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Runner has process management, including an inetd replacement

LICENSE=	MIT

DEPRECATED=	Use devel/py-twisted instead
EXPIRATION_DATE=2017-09-30

USE_PYTHON=	autoplist distutils
USES=		python:2 tar:bzip2 twisted

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/runner/portmap.so

.include <bsd.port.mk>
