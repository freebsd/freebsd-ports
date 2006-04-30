# New ports collection makefile for:   atomix
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/atomix/Makefile,v 1.9 2006/04/13 07:52:34 bland Exp $
#

PORTNAME=	atomix
PORTVERSION=	2.14.0
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A yet another little mind game

USE_X_PREFIX=	yes
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
