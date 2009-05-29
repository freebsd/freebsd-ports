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

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="-c ${CFLAGS}"

PLIST_FILES=	bin/alienwave
PORTDOCS=	README STORY TO_DO

OPTIONS=	RANDOM_LEVELS	"Enable random waves" off \
		LEVEL_EASY	"Killing Xzarna: easy (default: medium)" off \
		LEVEL_HARD	"Killing Xzarna: hard (default: medium)" off

.include <bsd.port.pre.mk>

.if defined(WITH_LEVEL_EASY)
CFLAGS+=	-DLEV_EASY
.endif

.if defined(WITH_LEVEL_HARD)
CFLAGS+=	-DLEV_HARD
.endif

.if defined(WITH_RANDOM_LEVELS)
CFLAGS+=	-DRANDOM_LEVELS
.endif

.if defined(WITH_LEVEL_EASY) && defined(WITH_LEVEL_HARD)
pre-everything::
	@${ECHO_CMD} "The LEVEL_EASY and LEVEL_HARD options are mutually exclusive."
	@${ECHO_CMD} "Please run 'make config' again."
	@${FALSE}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alienwave ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.post.mk>
