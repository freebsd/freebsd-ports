# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urwid
PORTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Curses-based user interface library for Python

LICENSE=	LGPL21

OPTIONS_DEFINE=	EXAMPLES

USES=		python
USE_PYTHON=	distutils autoplist

PORTEXAMPLES=	bigtext.py \
		browse.py \
		calc.py \
		dialog.py \
		edit.py \
		fib.py \
		graph.py \
		input_test.py \
		lcd_cf635.py \
		palette_test.py \
		pop_up.py \
		subproc.py \
		tour.py \
		treesample.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/)

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} -m urwid.tests

.include <bsd.port.mk>
