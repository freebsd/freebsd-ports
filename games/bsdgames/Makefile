# Created by: Mark Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdgames
PORTVERSION=	4.8.1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	LOCAL/adamw

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Traditional BSD games taken from DragonFly BSD

LICENSE=	BSD3CLAUSE

CONFLICTS=	hangman-[0-9]*

USES=		ncurses tar:xz uidfix
MAKE_ENV=	NO_WERROR=1
MAKE_ARGS=	BINGRP=${BINGRP}

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

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s/NOMAN/NO_MAN/" \
		${WRKSRC}/backgammon/teachgammon/Makefile \
		${WRKSRC}/canfield/cfscores/Makefile \
		${WRKSRC}/snake/snscore/Makefile \
		${WRKSRC}/fortune/unstr/Makefile \
		${WRKSRC}/primes/Makefile
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
	@${FIND} ${WRKSRC} -type f -name Makefile \
		| ${XARGS} ${REINPLACE_CMD} -e 's/-lprivate_ncurses/-lncurses/'

pre-install:
.for d in atc larn quiz.db
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/$d
.endfor
.for d in atc battlestar hackdir/save larn phantasia
	@${MKDIR} ${STAGEDIR}/var/games/$d
.endfor

post-install:
# avoid conflict with games/bs and shells/fish
.for prog in bs fish
	${MV} ${STAGEDIR}${PREFIX}/bin/${prog} ${STAGEDIR}${PREFIX}/bin/${prog}-game
	${MV} ${STAGEDIR}${MAN6PREFIX}/man/man6/${prog}.6.gz ${STAGEDIR}${MAN6PREFIX}/man/man6/${prog}-game.6.gz
.endfor

	@${TOUCH} ${STAGEDIR}/var/games/atc_score
	@${FIND} ${STAGEDIR}/var/games -type f -exec ${MV} {} {}.sample \;

dist:
	fetch -o- https://github.com/DragonFlyBSD/DragonFlyBSD/archive/v${PORTVERSION}.zip | \
		unzip - DragonFlyBSD-${PORTVERSION}/games/\*
	mv DragonFlyBSD-${PORTVERSION}/games bsdgames-${PORTVERSION}
	tar -cvf bsdgames-${PORTVERSION}.tar bsdgames-${PORTVERSION}
	xz -v bsdgames-${PORTVERSION}.tar
	@echo
	@echo 'UPLOAD THE DISTFILE BEFORE YOU FORGET'
	@echo '====================================='

.include <bsd.port.post.mk>
