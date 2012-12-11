# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

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

OPTIONS_DEFINE=	RANDOM_LEVELS DOCS
OPTIONS_DEFAULT=LEVEL_MEDIUM
OPTIONS_SINGLE=	LEVEL
OPTIONS_SINGLE_LEVEL=	LEVEL_EASY LEVEL_MEDIUM LEVEL_HARD
RANDOM_LEVELS_DESC=	Enable random waves
LEVEL_EASY_DESC=	Killing Xzarna: easy
LEVEL_MEDIUM_DESC=	Killing Xzarna: medium
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
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
