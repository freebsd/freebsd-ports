# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomegames2
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-games/2.4
DISTNAME=	gnome-games-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the Gnome 2 Desktop Environment

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier libgnomeui
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFLICTS=	sol-1.0.*

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
