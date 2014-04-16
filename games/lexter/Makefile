# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lexter
PORTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time word puzzle for text terminals

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--localstatedir=/var/games
USES=		gettext

.include <bsd.port.mk>
