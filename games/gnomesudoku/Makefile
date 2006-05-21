# New ports collection makefile for:	gnome-sudoku
# Date created:				2005-09-12
# Whom:					Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomesudoku
PORTVERSION=	0.4.0
#PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-sudoku
DISTNAME=	gnome-sudoku-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org
COMMENT=	GNOME Sudoku game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

BROKEN=		Configure fails

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	pygnome2 pygnomeextras

.include <bsd.port.mk>
