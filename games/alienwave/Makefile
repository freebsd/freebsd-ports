# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	alienwave
PORTVERSION=	0.4.0
CATEGORIES=	games
MASTER_SITES=	http://www.alessandropira.org/alienwave/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shoot'em up game written using ncurses

LICENSE=	GPLv2

OPTIONS_DEFINE=	RANDOM_LEVELS DOCS
OPTIONS_DEFAULT=LEVEL_MEDIUM
OPTIONS_SINGLE=	LEVEL
OPTIONS_SINGLE_LEVEL=	LEVEL_EASY LEVEL_MEDIUM LEVEL_HARD
RANDOM_LEVELS_DESC=	Enable random waves
LEVEL_EASY_DESC=	Killing Xzarna: easy
LEVEL_MEDIUM_DESC=	Killing Xzarna: medium
LEVEL_HARD_DESC=	Killing Xzarna: hard

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	${PORTNAME}

PORTDOCS=	README STORY TO_DO
PLIST_FILES=	bin/alienwave

NO_STAGE=	yes
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

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC /s|^|#| ; \
		 /^CFLAGS /s|^|#| ; \
		 s|-lncurses|-lcurses| ; \
		 /strip /s|^|#|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} alienwave ${PREFIX}/bin)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
