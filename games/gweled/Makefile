# New ports collection makefile for:	gweled
# Date created:		November 28, 2003
# Whom:			James Earl
#
# $FreeBSD$
#

PORTNAME=	gweled
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	http://sebdelestaing.free.fr/gweled/Release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME version of the game called "Bejeweled" or "Diamond Mine"

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeui librsvg2
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/var/games|${PREFIX}/share/gnome/games|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$${MKDIRPROG-mkdir}|mkdir -p|' \
		${WRKSRC}/install-sh

.include <bsd.port.mk>
