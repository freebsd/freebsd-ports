# Ports collection makefile for:  games
# Date created:			  20 Nov 2002
# Whom:				  Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freebsd-games
PORTVERSION=	5.1.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=markm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD-modified "Standard" BSD games

USE_REINPLACE=	yes
USE_BZIP2=	yes

MAN6=	\
	adventure.6 \
	arithmetic.6 \
	atc.6 \
	backgammon.6 \
	battlestar.6 \
	bs.6 \
	canfield.6 \
	cfscores.6 \
	cribbage.6 \
	fish.6 \
	hack.6 \
	hangman.6 \
	larn.6 \
	mille.6 \
	phantasia.6 \
	piano.6 \
	pig.6 \
	quiz.6 \
	robots.6 \
	rogue.6 \
	sail.6 \
	snake.6 \
	snscore.6 \
	trek.6 \
	worm.6 \
	wump.6

MANCOMPRESSED=	maybe

PATHNAME_FILES=	atc/pathnames.h \
		cribbage/pathnames.h \
		fish/pathnames.h \
		larn/pathnames.h \
		quiz/datfiles/index \
		quiz/pathnames.h \
		wump/pathnames.h

post-extract:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} extract)

post-patch:
	@${FIND} ${WRKSRC} -name '*.c' -or -name '*.h' -or -name '*.6' -or \
		-name 'index' | ${XARGS} ${REINPLACE_CMD} -e \
		's|share/games|local/share/games|g'
	@for f in ${PATHNAME_FILES}; do \
		${REINPLACE_CMD} -e 's|/usr/local/local/local|${PREFIX}|g' \
			${WRKSRC}/$${f}; \
	done
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		"${WRKSRC}/hack/hack.unix.c"

.include <bsd.port.mk>
