PORTNAME=	gnome-shell-extension-recent-items
DISTVERSION=	46.2
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Recent items extension for the GNOME shell
WWW=		https://github.com/bananenfisch/RecentItems

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnome
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bananenfisch
GH_PROJECT=	RecentItems

GLIB_SCHEMAS=	org.gnome.shell.extensions.recent-items.gschema.xml
UUID_EXTENSION=	RecentItems@bananenfisch.net

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"46"|"46", "47"|g' \
		${WRKSRC}/metadata.json

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${MV} "${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}/schemas/${GLIB_SCHEMAS}" \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/

.include <bsd.port.mk>
