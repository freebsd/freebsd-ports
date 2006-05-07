# New ports collection makefile for:	clanbomber
# Date created:				10 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clanbomber
PORTVERSION=	1.05
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bomberman-like multiplayer game

LIB_DEPENDS=	clanCore.2:${PORTSDIR}/devel/clanlib

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS+=	-fpermissive

.include <bsd.port.pre.mk>

.if !defined(DISPLAY)
IGNORE=	needs an X-display to build (binary is used to create resource files)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/clanbomber/Resources.cpp

	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|g' \
		${WRKSRC}/clanbomber/ClanBomber.cpp

.include <bsd.port.post.mk>
