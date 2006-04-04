# New ports collection makefile for:	gnome-menu-editor
# Date created:		2005-03-01
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnome-menu-editor/Makefile,v 1.8 2005/09/08 18:09:45 marcus Exp $
#

PORTNAME=	gnome-menu-editor
PORTVERSION=	0.6
CATEGORIES=	deskutils
MASTER_SITES=	http://manny.cluecoder.org/packages/gnome-menu-editor/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple menu editor for Gnome

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomemenus intlhack
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
# Make .desktop file valid to desktop-file-validate
	@${REINPLACE_CMD} -e 's|OnlyShowIn=GNOME|OnlyShowIn=GNOME;|' \
		${WRKSRC}/data/gnome-menu-editor.desktop.in

post-install:
	${LN} -sf ${PREFIX}/bin/gnome-menu-editor \
		${PREFIX}/bin/gmenu-simple-editor

.include <bsd.port.mk>
