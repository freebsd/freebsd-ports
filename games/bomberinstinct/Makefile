# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bomberinstinct
PORTVERSION=	0.8.9
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Bomber%20Instinct/BomberInstinct-${PORTVERSION}
DISTNAME=	BomberInstinct-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bomberman-like multiplayer game

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		gettext gmake sdl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl -pthread
# Upstream is dead.
CFLAGS+=	-fcommon

EXPIRATION_DATE=	2020-09-30
DEPRECATED=		Unmaintained and dead upstream

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<SDL/|<|g'

.include <bsd.port.mk>
