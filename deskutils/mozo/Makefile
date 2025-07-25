PORTNAME=	mozo
PORTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Editor for the freedesktop.org menu specification
WWW=		https://mate-desktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/mate-desktop-item-edit:x11/mate-panel

USES=		gettext-tools gmake gnome localbase mate pkgconfig \
		python tar:xz
USE_GNOME=	gtk30 intltool pygobject3
USE_MATE=	menus
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
NO_ARCH=	yes

PORTSCOUT=	limitw:1,even

NLS_USES=	gettext
OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
