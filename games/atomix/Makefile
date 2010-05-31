# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/atomix/Makefile,v 1.14 2007/09/10 05:39:33 mezz Exp $
#

PORTNAME=	atomix
PORTVERSION=	2.14.0
PORTREVISION=	9
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A yet another little mind game

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's/games\.games/games:games/' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^$$/d' ${WRKSRC}/po/POTFILES.in

.include <bsd.port.mk>
