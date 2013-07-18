# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	xpat2
PORTVERSION=	1.07
DISTVERSIONSUFFIX=	-src
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/solitaires

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 solitaire game with 14 variations

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		imake
USE_XORG=	xaw

CFLAGS+=	-D_POSIX_SOURCE -DNO_CUSERID -D_POSIX_SAVED_IDS

MAN6=		xpat2.6

DESKTOP_ENTRIES="XPat2" "" "" "${PORTNAME}" "" ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/xpat2.man

post-install:
	${CHOWN} root:games ${PREFIX}/bin/xpat2
	${CHMOD} 2555 ${PREFIX}/bin/xpat2
.if !exists(/var/games/xpat.log)
.if !exists(/var/games)
	${MKDIR} /var/games
	${CHMOD} 775 /var/games
.endif
	${ECHO_CMD} -n > /var/games/xpat.log
	${CHOWN} root:games /var/games/xpat.log
	${CHMOD} 664 /var/games/xpat.log
.endif

.include <bsd.port.mk>
