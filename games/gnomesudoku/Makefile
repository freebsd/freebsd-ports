# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnomesudoku
PORTVERSION=	0.6.0
PORTREVISION=	10
CATEGORIES=	games gnome
MASTER_SITES=	SF/gnome-sudoku/gnome-sudoku/${PORTVERSION}
DISTNAME=	gnome-sudoku-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME Sudoku game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow

USES=		display pathfix python
USE_GNOME=	gnomeprefix pygnome2 pygnomedesktop
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	gnome-sudoku

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/tools/gsudoku_distutils.py

.include <bsd.port.mk>
