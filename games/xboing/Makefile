PORTNAME=	xboing
PORTVERSION=	2.4
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 arcade game

LICENSE=	MIT

USES=		cpe imake xorg
USE_XORG=	xpm xext x11

WRKSRC=		${WRKDIR}/xboing

OPTIONS_DEFINE=SOUND
OPTIONS_DEFAULT=SOUND
OPTIONS_SUB=yes

SOUND_MAKE_ENV=	WITHOUT_AUDIO=True

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/X11/xboing/.xboing.scr

.include <bsd.port.mk>
