# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	xpired
PORTVERSION=	1.22
PORTREVISION=	22
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-linux/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux_source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Action-puzzle maze escape game (SDL)

USE_SDL=	gfx image mixer sdl
WRKSRC=		${WRKDIR}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpired ${WRKSRC}/xpiredit \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/img
	@${MKDIR} ${STAGEDIR}${DATADIR}/snd
.for files in xpired.lvl xpired.cfg bgimages.txt readme.txt xpired.dmo
	${INSTALL_DATA} ${WRKSRC}/${files} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/img/* ${STAGEDIR}${DATADIR}/img
	${INSTALL_DATA} ${WRKSRC}/snd/* ${STAGEDIR}${DATADIR}/snd

.include <bsd.port.mk>
