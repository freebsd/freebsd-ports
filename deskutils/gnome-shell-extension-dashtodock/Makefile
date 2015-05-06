# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-dashtodock
PORTVERSION=	0.0.0.20141126
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convert the dash into a dock

BUILD_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.dash-to-dock.gschema.xml

GH_ACCOUNT=	micheleg
GH_TAGNAME=	8d2ccc7
GH_PROJECT=	dash-to-dock

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/dash-to-dock@micxgx.gmail.com
		@(cd ${WRKSRC} && ${CP} schemas/org.gnome.shell.extensions.dash-to-dock.gschema.xml \
			${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/)
		@${RM} -fr ${WRKSRC}/schemas
		@(cd ${WRKSRC} && ${CP} -pPR * \
			${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/dash-to-dock@micxgx.gmail.com)

.include <bsd.port.mk>
