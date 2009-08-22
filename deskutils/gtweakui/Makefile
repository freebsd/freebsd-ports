# New ports collection makefile for:   gTweakUI
# Date Created:			17 June 2004
# Whom:				Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#    $MCom: ports/deskutils/gtweakui/Makefile,v 1.2 2007/05/19 21:36:03 marcus Exp $

PORTNAME=	gTweakUI
PORTVERSION=	0.4.0
PORTREVISION=	8
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of simple dialogs as a front end to GConf

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui gconf2 libglade2 intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DESKTOP_FILES=	gtweakui-galeon.desktop.in \
				gtweakui-menus.desktop.in \
				gtweakui-nautilus.desktop.in \
				gtweakui-session.desktop.in

post-patch:
.for FILE in ${DESKTOP_FILES}
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
			-e 's|Settings;|&AdvancedSettings;|g' ${WRKSRC}/${FILE}
.endfor
	@${REINPLACE_CMD} 's|$$(datadir)/applications|$$(datadir)/control-center-2.0/capplets|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
