# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-backslide/Makefile 19681 2014-05-23 14:43:21Z gusi $

PORTNAME=	gnome-shell-extension-backslide
PORTVERSION=	0.0.0.20140520
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://bitbucket.org/LukasKnuth/backslide/get/
DISTFILES=	7e36a49fc5e1.zip
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome-shell extension for background slideshow

BUILD_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas

WRKSRC=		${WRKDIR}/LukasKnuth-backslide-7e36a49fc5e1

USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	glib20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.backslide.gschema.xml

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|Me.dir.get_child(\'schemas\').get_path()|'${PREFIX}/share/glib-2.0/schemas'|g" \
		${WRKSRC}/backslide@codeisland.org/settings.js

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/
	@(cd ${WRKSRC} && ${CP} backslide\@codeisland.org/schemas/org.gnome.shell.extensions.backslide.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/)
	@${RM} -fr ${WRKSRC}/backslide\@codeisland.org/schemas
	@(cd ${WRKSRC} && ${CP} -pPR backslide\@codeisland.org \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/)

.include <bsd.port.mk>
