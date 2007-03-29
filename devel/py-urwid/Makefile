# New ports collection makefile for:	py-urwid
# Date created:		7 December 2004
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	urwid
PORTVERSION=	0.9.8
CATEGORIES=	devel python
MASTER_SITES=	http://excess.org/urwid/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based user interface library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@# disable setuptools for now
	${REINPLACE_CMD} 's/setuptools/xxsetuptools/g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
