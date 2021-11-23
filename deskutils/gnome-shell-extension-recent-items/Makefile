# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>

PORTNAME=	gnome-shell-extension-recent-items
PORTVERSION=	40
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Recent items extensions for the GNOME3 shell

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnome
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bananenfisch
GH_PROJECT=	RecentItems

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net

.include <bsd.port.mk>
