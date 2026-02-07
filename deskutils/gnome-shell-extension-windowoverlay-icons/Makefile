PORTNAME=	gnome-shell-extension-windowoverlay-icons
PORTVERSION=	36
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Show application icons on the windows overview
WWW=		https://github.com/sustmi/gnome-shell-extensions-sustmi

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Does not support recent gnome-shell

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GLIB_SCHEMAS=	org.gnome.shell.extensions.windowoverlay-icons.gschema.xml

GH_ACCOUNT=	sustmi
GH_TAGNAME=	ad7366d

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

FILES=	README.md convenience.js \
	extension.js metadata.json \
	prefs.js prefs.xml \
	stylesheet.css

post-patch:
	@${REINPLACE_CMD} -e 's|"3.26"|"3.26","3.28"|g' \
		${WRKSRC}/metadata.json

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/windowoverlay-icons@gnome-shell-extensions.sustmi.github.com
	cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/schemas/org.gnome.shell.extensions.windowoverlay-icons.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
.for file in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/windowoverlay-icons@gnome-shell-extensions.sustmi.github.com/
.endfor
	cd ${WRKSRC}/locale && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/locale/
	@${RM} ${STAGEDIR}${PREFIX}/share/locale/.gitkeep

.include <bsd.port.mk>
