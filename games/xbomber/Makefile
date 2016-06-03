# Created by: marcus
# $FreeBSD$

PORTNAME=	xbomber
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/xbomber/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Game based on "Super Bomberman" for the Super Nintendo

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XORG=	x11

MAKEFILE=	makefile

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbomber ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -C ${WRKSRC} -cf - bitmaps jungle levels pixmaps sounds | \
		${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -
	@${FIND} ${STAGEDIR}${PREFIX}/share/xbomber -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README.txt LEVELS.txt SOUND.txt GRAPHICS.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
