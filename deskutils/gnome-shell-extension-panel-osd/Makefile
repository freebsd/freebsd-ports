# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-panel-osd/Makefile 19807 2014-08-14 07:04:43Z gusi $

PORTNAME=	gnome-shell-extension-panel-osd
PORTVERSION=	0.0.0.20140520
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OSD extension for the GNOME3 shell

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas

WRKSRC=		${WRKDIR}/jenslody-gnome-shell-extension-panel-osd-fc4b382

USES=		gettext gmake libtool pkgconfig tar:xz
USE_GNOME=	glib20 intltool
USE_GITHUB=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.panel-osd.gschema.xml

GH_ACCOUNT=	jenslody
GH_PROJECT=	gnome-shell-extension-panel-osd
GH_TAGNAME=	fc4b3820b5
GH_COMMIT=	fc4b3820b5

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

pre-configure:
		cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
