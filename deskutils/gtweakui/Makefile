# New ports collection makefile for:   gTweakUI
# Date Created:			17 June 2004
# Whom:				Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	gTweakUI
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtweakui
DIST_SUBDIR=	gnome2

MAINTAINER=	asa@gascom.ru
COMMENT=	A collection of simple dialogs as a front end to GConf

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui gconf2 libglade2 intlhack
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

DESKTOP_FILES=	gtweakui-galeon.desktop.in \
				gtweakui-menus.desktop.in \
				gtweakui-nautilus.desktop.in \
				gtweakui-session.desktop.in

post-patch:
.for FILE in ${DESKTOP_FILES}
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share/gnome|g' \
			-e 's|Settings;|&AdvancedSettings;|g' ${WRKSRC}/${FILE}
.endfor
	@${REINPLACE_CMD} 's|$$(datadir)/applications|$$(datadir)/control-center-2.0/capplets|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
