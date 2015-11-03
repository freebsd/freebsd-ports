# Created by: Pedro Garcia Freitas <sawp@sawp.com.br>
# $FreeBSD$

PORTNAME=	x-tile
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	deskutils devel python
MASTER_SITES=	http://www.giuspen.com/software/

MAINTAINER=	sawp@sawp.com.br
COMMENT=	GNOME applet to tile the opened windows

LICENSE=	GPLv2

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USE_GNOME=	pygtk2
USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	X_Tile

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PYDISTUTILS_BUILD_TARGET=	--without-gettext build
PYDISTUTILS_INSTALL_TARGET=	--without-gettext install
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/x-tile ${WRKSRC}/linux/x-tile.desktop \
		${WRKSRC}/modules/cons.py
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
