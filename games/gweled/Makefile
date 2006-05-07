# New ports collection makefile for:	gweled
# Date created:		November 28, 2003
# Whom:			James Earl
#
# $FreeBSD$
#

PORTNAME=	gweled
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	http://sebdelestaing.free.fr/gweled/Release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME version of the game called "Bejeweled" or "Diamond Mine"

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libgnomeui librsvg2
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/var/games|${PREFIX}/share/gnome/games|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$${MKDIRPROG-mkdir}|mkdir -p|' \
		${WRKSRC}/install-sh

.include <bsd.port.mk>
