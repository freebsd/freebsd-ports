# New ports collection makefile for:	alienwave
# Date created:			23 July 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	alienwave
PORTVERSION=	0.3.0
CATEGORIES=	games
MASTER_SITES=	http://www.alessandropira.org/alienwave/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shoot'em up game written using ncurses

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="-c ${CFLAGS}"

PLIST_FILES=	bin/alienwave
PORTDOCS=	README STORY TO_DO

OPTIONS_DEFINE=	RANDOM_LEVELS LEVEL DOCS
OPTIONS_SINGLE=	LEVEL
OPTIONS_SINGLE_LEVEL=	LEVEL_EASY LEVEL_HARD
RANDOM_LEVELS_DESC=	Enable random waves
LEVEL_DESC=	Choose a level different from medium
LEVEL_EASY_DESC=	Killing Xzarna: easy
LEVEL_HARD_DESC=	Killing Xzarna: hard

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLEVEL_EASY}
CFLAGS+=	-DLEV_EASY
.endif

.if ${PORT_OPTIONS:MLEVEL_HARD}
CFLAGS+=	-DLEV_HARD
.endif

.if ${PORT_OPTIONS:MRANDOM_LEVELS}
CFLAGS+=	-DRANDOM_LEVELS
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alienwave ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
