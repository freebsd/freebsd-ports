# New ports collection makefile for:	jools
# Date created:				6 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	jools
PORTVERSION=	0.10
CATEGORIES=	games
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/jools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Addictive jewel-swapping puzzle game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} ${WRKSRC}/setup.py install --prefix=${PREFIX}

.include <bsd.port.mk>
