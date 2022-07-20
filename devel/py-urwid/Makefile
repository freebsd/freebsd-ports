PORTNAME=	urwid
PORTVERSION=	2.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Curses-based user interface library for Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils unittest

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/urwid/str_util*.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
