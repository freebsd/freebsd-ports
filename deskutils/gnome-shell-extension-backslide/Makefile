# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-backslide
PORTVERSION=	0.0.0.20140520
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://bitbucket.org/LukasKnuth/backslide/get/
DISTFILES=	7e36a49fc5e1.zip
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome-shell extension for background slideshow

BROKEN=		checksum mismatch

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

WRKSRC=		${WRKDIR}/LukasKnuth-backslide-7e36a49fc5e1

USES=		gettext gmake gnome pkgconfig tar:xz
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.backslide.gschema.xml

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|Me.dir.get_child(\'schemas\').get_path()|'${PREFIX}/share/glib-2.0/schemas'|g" \
		${WRKSRC}/backslide@codeisland.org/settings.js
	@${REINPLACE_CMD} -e 's|3.12|3.12", "3.14", "3.16|g' \
		${WRKSRC}/backslide\@codeisland.org/metadata.json

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/
	@(cd ${WRKSRC} && ${CP} backslide\@codeisland.org/schemas/org.gnome.shell.extensions.backslide.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/)
	@${RM} -r ${WRKSRC}/backslide\@codeisland.org/schemas
	@(cd ${WRKSRC} && ${CP} -pPR backslide\@codeisland.org \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/)

.include <bsd.port.mk>
