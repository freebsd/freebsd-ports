# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twisted
PORTVERSION=	16.4.1
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.0:devel/py-zope.interface

# Actually 2.7,3.3+
USES=		python tar:bzip2
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

post-install:
.if ${PYTHON_REL} < 3000
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/python/_sendmsg.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/runner/portmap.so
.endif
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/test/raiser.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m twisted.trial -e twisted

.include <bsd.port.post.mk>
