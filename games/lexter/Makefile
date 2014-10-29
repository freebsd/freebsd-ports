# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lexter
PORTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time word puzzle for text terminals

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--localstatedir=/var/games
USES=		gettext

post-install:
	@${MKDIR} ${STAGEDIR}/var/games
	@${TOUCH} ${STAGEDIR}/var/games/lexter.scores.sample

.include <bsd.port.mk>
