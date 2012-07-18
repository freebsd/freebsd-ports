# New ports collection makefile for:	py-urwid
# Date created:		7 December 2004
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	urwid
PORTVERSION=	1.0.2
CATEGORIES=	devel python
MASTER_SITES=	http://excess.org/urwid/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Curses-based user interface library for Python

LICENSE=	LGPL21

OPTIONS_DEFINE=	EXAMPLES

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

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

.include <bsd.port.options.mk>

post-patch:
# disable setuptools for now
	@${REINPLACE_CMD} 's/setuptools/do_not_use_&/g' ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
