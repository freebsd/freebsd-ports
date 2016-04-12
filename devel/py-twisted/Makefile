# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twisted
PORTVERSION=	15.5.0
CATEGORIES=	devel net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.0:devel/py-zope.interface

USES=		python:2 tar:bzip2
USE_PYTHON=	distutils

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.c" -and -exec ${RM} {} \;
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/python/_sendmsg.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/test/raiser.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/runner/portmap.so

.include <bsd.port.mk>
