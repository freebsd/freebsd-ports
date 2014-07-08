# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/games/atomix/Makefile,v 1.14 2007/09/10 05:39:33 mezz Exp $

PORTNAME=	atomix
PORTVERSION=	2.14.0
PORTREVISION=	12
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another little mind game

USES=		gettext gmake pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm

post-patch:
	@${REINPLACE_CMD} -e 's/games\.games/games:games/' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^$$/d' ${WRKSRC}/po/POTFILES.in

.include <bsd.port.mk>
