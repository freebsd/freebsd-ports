# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-gtile/Makefile 19681 2014-05-23 14:43:21Z gusi $

PORTNAME=	gnome-shell-extension-gtile
PORTVERSION=	0.0.0.20140520
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome-shell extension that tiles windows

BUILD_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas

WRKSRC=		${WRKDIR}/vibou-vibou.gTile-259b0dd

USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.gtile.gschema.xml

GH_ACCOUNT=	vibou
GH_TAGNAME=	259b0dd59f
GH_COMMIT=	259b0dd59f
GH_PROJECT=	vibou.gTile

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
		@${REINPLACE_CMD} -e 's|3.10|3.10","3.12|g' \
			${WRKSRC}/metadata.json
		@${REINPLACE_CMD} -e "s|Extension.dir.get_child('schemas').get_path()|'${PREFIX}/share/glib-2.0/schemas'|g" \
			${WRKSRC}/utils.js

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/gTile@vibou
		@(cd ${WRKSRC} && ${CP} schemas/org.gnome.shell.extensions.gtile.gschema.xml \
			${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/)
		@${RM} -fr ${WRKSRC}/schemas
		@(cd ${WRKSRC} && ${CP} -pPR * \
			${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/gTile@vibou)

.include <bsd.port.mk>
