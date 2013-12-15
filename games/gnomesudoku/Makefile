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

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USES=		pathfix display
USE_GNOME=	gnomeprefix pygnome2 pygnomedesktop

PYDISTUTILS_PKGNAME=	gnome-sudoku

NO_STAGE=	yes


post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/tools/gsudoku_distutils.py
.include <bsd.port.mk>
