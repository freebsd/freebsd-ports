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

LEVEL_EASY_CFLAGS=	-DLEV_EASY
LEVEL_HARD_CFLAGS=	-DLEV_HARD
RANDOM_LEVELS_CFLAGS=	-DRANDOM_LEVELS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC /s|^|#| ; \
		 /^CFLAGS /s|^|#| ; \
		 s|-lncurses|-lcurses| ; \
		 /strip /s|^|#|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} alienwave ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
