# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urwid
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Curses-based user interface library for Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	EXAMPLES

USES=		python
USE_PYTHON=	autoplist distutils

PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/urwid/str_util.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}/)

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m urwid.tests

.include <bsd.port.mk>
