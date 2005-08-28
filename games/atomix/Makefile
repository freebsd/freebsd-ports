# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/games/atomix/Makefile,v 1.2 2005/08/04 04:03:32 marcus Exp $
#

PORTNAME=	atomix
PORTVERSION=	1.2.2a
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A yet another little mind game

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's/games\.games/games:games/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
