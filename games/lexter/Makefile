PORTNAME=	lexter
PORTVERSION=	1.0.3
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time word puzzle for text terminals
WWW=		https://www.kyne.com.au/~mark/software/lexter.php

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--localstatedir=/var/games
USES=		gettext ncurses

post-install:
	@${MKDIR} ${STAGEDIR}/var/games
	@${TOUCH} ${STAGEDIR}/var/games/lexter.scores.sample

.include <bsd.port.mk>
