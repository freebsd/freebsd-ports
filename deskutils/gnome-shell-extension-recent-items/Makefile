# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-recent-items/Makefile 19931 2014-10-01 14:32:38Z kwm $

PORTNAME=	gnome-shell-extension-recent-items
PORTVERSION=	0.0.0.20141001
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.bananenfisch.net/code/
DISTNAME=	RecentItems-11
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Recent items extensions for the GNOME3 shell

WRKSRC=		${WRKDIR}/RecentItems@bananenfisch.net

USE_GNOME=	glib20
USE_LDCONFIG=	yes

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net
	@(cd ${WRKSRC} && ${CP} -pPR * \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net)
	@chmod +r ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/RecentItems@bananenfisch.net/metadata.json

.include <bsd.port.mk>
