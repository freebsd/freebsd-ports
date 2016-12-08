# Created by: Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$
#    $MCom: ports/deskutils/gtweakui/Makefile,v 1.2 2007/05/19 21:36:03 marcus Exp $

PORTNAME=	gTweakUI
PORTVERSION=	0.4.0
PORTREVISION=	12
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of simple dialogs as a front end to GConf

USES=		gmake pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix libgnomeui gconf2 libglade2 intlhack
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
