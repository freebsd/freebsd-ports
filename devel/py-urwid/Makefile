# New ports collection makefile for:	py-urwid
# Date created:		7 December 2004
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	urwid
PORTVERSION=	0.9.8.4
CATEGORIES=	devel python
MASTER_SITES=	http://excess.org/urwid/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Curses-based user interface library for Python

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
		test_urwid.py \
		tour.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-patch:
	@# disable setuptools for now
	${REINPLACE_CMD} 's/setuptools/xxsetuptools/g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
