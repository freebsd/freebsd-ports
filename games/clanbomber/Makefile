# New ports collection makefile for:	clanbomber
# Date created:				10 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clanbomber
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bomberman-like multiplayer game

LIB_DEPENDS=	clanCore-0.8:${PORTSDIR}/devel/clanlib

BROKEN=		Does not compile with the newer clanCore

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=	-fpermissive
USE_DISPLAY=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/clanbomber/Resources.cpp

	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|g' \
		${WRKSRC}/clanbomber/ClanBomber.cpp

.include <bsd.port.mk>
