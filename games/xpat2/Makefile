# Created by: Matthew Hunt <mph@pobox.com>
# $FreeBSD$

PORTNAME=	xpat2
PORTVERSION=	1.07
DISTVERSIONSUFFIX=	-src
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/solitaires

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 solitaire game with 14 variations

LICENSE=	GPLv2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		imake xorg
USE_XORG=	xaw

CFLAGS+=	-D_POSIX_SOURCE -DNO_CUSERID -D_POSIX_SAVED_IDS

DATADIR=	${PREFIX}/share/xpat

DESKTOP_ENTRIES="XPat2" "" "" "${PORTNAME}" "" ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)\($$(XPAT.*DIR)\)|\1$$(DESTDIR)\2|g ; \
		 s|\([[:blank:]]\)\($$(APPDEFSDIR)\)|\1$$(DESTDIR)\2|g ; \
		 /chown/s|^|#| ; \
		 s|\(xpat2.6\)x|\1|g' ${WRKSRC}/Imakefile
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/xpat2.man

post-install:
	@${MKDIR} ${STAGEDIR}/var/games
	${TOUCH} ${STAGEDIR}/var/games/xpat.log.sample

.include <bsd.port.mk>
