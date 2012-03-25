# New ports collection makefile for:	x-tile
# Date created:		2010-09-17
# Whom:			Pedro Garcia Freitas <sawp@sawp.com.br>
#
# $FreeBSD$
#

PORTNAME=	x-tile
PORTVERSION=	2.2.1
CATEGORIES=	deskutils devel python
MASTER_SITES=	http://www.giuspen.com/software/

MAINTAINER=	sawp@sawp.com.br
COMMENT=	A GNOME applet to tile the opened windows

LICENSE=	GPLv2

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	X_Tile

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/x-tile ${WRKSRC}/linux/x-tile.desktop \
		${WRKSRC}/modules/cons.py

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PYDISTUTILS_BUILD_TARGET=	--without-gettext build
PYDISTUTILS_INSTALL_TARGET=	--without-gettext install
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
