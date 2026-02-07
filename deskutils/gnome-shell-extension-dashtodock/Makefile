PORTNAME=	gnome-shell-extension-dashtodock
DISTVERSIONPREFIX=	extensions.gnome.org-v
DISTVERSION=	102
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convert the dash into a dock
WWW=		https://micheleg.github.io/dash-to-dock/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sassc>0:textproc/sassc
RUN_DEPENDS=	gnome-shell>=47.0:x11/gnome-shell \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		gettext-tools gmake gnome
USE_GNOME=	glib20 intltool:build

USE_GITHUB=	yes
GH_ACCOUNT=	micheleg
GH_PROJECT=	dash-to-dock

UUID_EXTENSION=	dash-to-dock@micxgx.gmail.com

SUB_FILES=	pkg-message
SUB_LIST=	UUID=${UUID_EXTENSION}

GLIB_SCHEMAS=	org.gnome.shell.extensions.dash-to-dock.gschema.xml

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/schemas/*.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.mk>
