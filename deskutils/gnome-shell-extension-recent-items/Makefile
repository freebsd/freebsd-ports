# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-recent-items/Makefile 19842 2014-09-03 08:48:11Z gusi $

PORTNAME=	gnome-shell-extension-recent-items
PORTVERSION=	0.0.0.20140903
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.bananenfisch.net/code/
DISTFILES=	RecentItems-9.tar.gz
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Recent items extensions for the GNOME3 shell

WRKSRC=		${WRKDIR}/RecentItems@bananenfisch.net

USES=		tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net
		@(cd ${WRKSRC} && ${CP} -pPR * \
                        ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net)

.include <bsd.port.mk>
