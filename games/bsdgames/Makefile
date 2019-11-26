# Created by: Mark Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdgames
PORTVERSION=	0.7
DISTVERSIONPREFIX=	v
PORTEPOCH=	2
CATEGORIES=	games

MAINTAINER=	jockl@pianojockl.org
COMMENT=	Traditional BSD games taken mostly from DragonFly BSD

LICENSE=	BSD3CLAUSE

USES=		ncurses tar:xz uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	pianojockl

CONFLICTS=	hangman-[0-9]*

MAKE_ENV=	NO_WERROR=1
MAKE_ARGS=	BINGRP=${BINGRP}

# contain /usr/share/games
SHAREPATH_FILES=atc/atc.6 \
		atc/pathnames.h \
		boggle/boggle/bog.h \
		boggle/boggle/boggle.6 \
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

post-patch:
	@for f in ${SHAREPATH_FILES}; do \
		${REINPLACE_CMD} -e 's|/usr/share/games|${PREFIX}/share/games|g' \
			${WRKSRC}/$${f}; \
	done
	@for f in ${GAMESPATH_FILES}; do \
		${REINPLACE_CMD} -e 's|/usr/games|${PREFIX}/bin|g' \
			${WRKSRC}/$${f}; \
	done

pre-install:
.for d in atc larn quiz.db boggle
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

.include <bsd.port.mk>
