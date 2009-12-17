# Ports collection makefile for:  games
# Date created:			  20 Nov 2002
# Whom:				  Mark Murray <markm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bsdgames
PORTVERSION=	2.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
# Fetched from http://gitweb.dragonflybsd.org/dragonfly.git/tree/v2.4.0:/games
# Content is stable, but file timestamps differ. Bad gitweb, no cookie!
MASTER_SITES=	https://www.spoerlein.net/pub/

MAINTAINER=	uqs@spoerlein.net
COMMENT=	Traditional BSD games taken from DragonFly BSD

WRKSRC=		${WRKDIR}/dragonfly
USE_BZIP2=	yes
MAKE_ENV+=	NO_WERROR=1
MAN6=	adventure.6 \
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
	hunt.6 \
	huntd.6 \
	larn.6 \
	mille.6 \
	phantasia.6 \
	piano.6 \
	pig.6 \
	quiz.6 \
	rain.6 \
	robots.6 \
	rogue.6 \
	sail.6 \
	snake.6 \
	snscore.6 \
	trek.6 \
	wargames.6 \
	worm.6 \
	worms.6 \
	wump.6

MANCOMPRESSED=	maybe

# contain /usr/share/games
SHAREPATH_FILES=atc/atc.6 \
		atc/pathnames.h \
		cribbage/cribbage.6 \
		cribbage/pathnames.h \
		fish/pathnames.h \
		larn/pathnames.h \
		quiz/datfiles/index \
		quiz/pathnames.h \
		quiz/quiz.6 \
		wump/pathnames.h

# contain /usr/games/*
GAMESPATH_FILES=backgammon/backgammon/backgammon.6 \
		backgammon/common_source/init.c \
		canfield/canfield/canfield.6 \
		cribbage/cribbage.6 \
		hunt/hunt/hunt.6 \
		hunt/huntd/huntd.6 \
		phantasia/pathnames.h \
		wargames/wargames.sh

# These keep score in /var/games
SGID_BINARIES=	atc battlestar canfield/canfield cribbage hack phantasia \
		robots sail snake/snake

post-patch:
	@for f in ${SHAREPATH_FILES}; do \
		${REINPLACE_CMD} -e 's|/usr/share/games|${PREFIX}/share/games|g' \
			${WRKSRC}/$${f}; \
	done
	@for f in ${GAMESPATH_FILES}; do \
		${REINPLACE_CMD} -e 's|/usr/games|${PREFIX}/bin|g' \
			${WRKSRC}/$${f}; \
	done
	@for f in ${SGID_BINARIES}; do \
		${REINPLACE_CMD} -e 's/HIDEGAME/SGIDGAME/' \
			${WRKSRC}/$${f}/Makefile; \
	done

# Only useful for DESTDIR
VARDIR?=	/var

pre-su-install:
	${MKDIR} ${VARDIR}
	mtree -deU -f ${FILESDIR}/var.mtree -p ${VARDIR}
	mtree -deU -f ${FILESDIR}/share.mtree -p ${PREFIX}/share

.include <bsd.port.mk>
