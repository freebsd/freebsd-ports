# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnomesudoku
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	games gnome
MASTER_SITES=	SF/gnome-sudoku/gnome-sudoku/${PORTVERSION}
DISTNAME=	gnome-sudoku-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME Sudoku game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
USES=		pathfix display:install
USE_GNOME=	gnomeprefix pygnome2 pygnomedesktop

PYDISTUTILS_PKGNAME=	gnome-sudoku

.include <bsd.port.mk>
