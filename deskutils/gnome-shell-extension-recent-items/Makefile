# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-recent-items
PORTVERSION=	15
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

post-patch:
		@${REINPLACE_CMD} -e 's|"3.22"|"3.22","3.24","3.26","3.28"|g' \
			${WRKSRC}/metadata.json

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net

.include <bsd.port.mk>
