# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atomix
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games gnome
MASTER_SITES=	http://jens.triq.net/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A yet another little mind game

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnome libgnomeui libgnomecanvas libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/games\.games/games:games/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
