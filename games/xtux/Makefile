# New ports collection makefile for:   xtux
# Date created:        23 December 2000
# Whom:    Göran Runfeldt <goranrunfeldt@home.se>
#
# $FreeBSD$
#

PORTNAME=	xtux
PORTVERSION=	2001.03.24
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=xtux
DISTNAME=	xtux-src-20010324

MAINTAINER=	goranrunfeldt@home.se

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_XPM=	yes
CFLAGS+=	-DDATADIR=\\\"${PREFIX}/share/xtux\\\"
WRKSRC=		${WRKDIR}/xtux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtux ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tux_serv ${PREFIX}/bin
	@strip ${PREFIX}/bin/xtux ${PREFIX}/bin/tux_serv

	@${MKDIR} ${PREFIX}/share/xtux/images/entities
	@${MKDIR} ${PREFIX}/share/xtux/images/events
	@${MKDIR} ${PREFIX}/share/xtux/images/items
	@${MKDIR} ${PREFIX}/share/xtux/images/weapons
	@${MKDIR} ${PREFIX}/share/xtux/images/tiles
	@${MKDIR} ${PREFIX}/share/xtux/maps

	${INSTALL_DATA} ${WRKSRC}/data/*.table ${PREFIX}/share/xtux
.for file in ascii.txt bios entities weapons
	${INSTALL_DATA} ${WRKSRC}/data/${file} ${PREFIX}/share/xtux
.endfor
.for dir in entities events items weapons tiles .
	${INSTALL_DATA} ${WRKSRC}/data/images/${dir}/*.xpm \
	${PREFIX}/share/xtux/images/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/data/maps/*.map \
	${PREFIX}/share/xtux/maps

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xtux
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/xtux
.endif

.include <bsd.port.mk>
