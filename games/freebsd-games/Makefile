# Ports collection makefile for:  games
# Date created:			  20 Nov 2002
# Whom:				  Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freebsd-games
PORTVERSION=	5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=markm

MAINTAINER=	ports@FreeBSD.org

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
	sail.6 \
	snake.6 \
	snscore.6 \
	trek.6 \
	worm.6 \
	wump.6

MANCOMPRESSED=	maybe

IGNOREFILES=	freebsd-games-5.0.tar.bz2

post-extract:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} extract)

.include <bsd.port.mk>
