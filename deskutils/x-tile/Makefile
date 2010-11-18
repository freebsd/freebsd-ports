# New ports collection makefile for:	x-tile
# Date created:		2010-09-17
# Whom:			Pedro Garcia Freitas <sawp@sawp.com.br>
#
# $FreeBSD$
#

PORTNAME=	x-tile
PORTVERSION=	1.8.1
CATEGORIES=	deskutils devel python
MASTER_SITES=	http://www.sawp.com.br/share/xtile/

MAINTAINER=	sawp@sawp.com.br
COMMENT=	A GNOME applet to tile the opened windows

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	X_Tile-${PYDISTUTILS_PKGVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|: docfiles|: []|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
