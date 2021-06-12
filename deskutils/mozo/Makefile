# Created by: FreeBSD GNOME Team

PORTNAME=	mozo
PORTVERSION=	1.24.1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Editor for the freedesktop.org menu specification

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/mate-desktop-item-edit:x11/mate-panel

USES=		gettext-tools gmake gnome localbase mate pathfix pkgconfig \
		python:3.7+ tar:xz
USE_MATE=	menus
USE_GNOME=	gtk30 intltool pygobject3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
NO_ARCH=	yes

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
	    ${WRKSRC}/Mozo/util.py

.include <bsd.port.mk>
