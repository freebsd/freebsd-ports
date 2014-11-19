# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-calculator/Makefile 19680 2014-05-23 14:40:39Z gusi $

PORTNAME=	gnome-shell-extension-calculator
PORTVERSION=	0.0.0.20140520
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple calculator in the gnome-shell search overview

BUILD_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell

WRKSRC=		${WRKDIR}/eonpatapon-gnome-shell-extension-calc-e4f4ac5

USES=		gettext gmake pkgconfig tar:xz
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GH_ACCOUNT=	eonpatapon
GH_TAGNAME=	e4f4ac5007
GH_COMMIT=	e4f4ac5007
GH_PROJECT=	gnome-shell-extension-calc

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/
		@(cd ${WRKSRC} && ${CP} -pPR calc\@patapon.info ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/)

.include <bsd.port.mk>
