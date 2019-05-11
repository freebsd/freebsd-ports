# Created by: Mark Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdgames
PORTVERSION=	5.5.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	https://deb.debian.org/debian/pool/main/b/bsdgames/:deb
DISTFILES=	${PORTNAME}_2.17.orig.tar.gz:deb

MAINTAINER=	jockl@pianojockl.org
COMMENT=	Traditional BSD games taken from DragonFly BSD

LICENSE=	BSD3CLAUSE

USES=		ncurses tar:xz uidfix
USE_GITHUB=	nodefault
GH_ACCOUNT=	DragonFlyBSD:bsd
GH_PROJECT=	DragonFlyBSD:bsd

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

post-extract:
	${MV} ${WRKSRC_bsd}/games  ${WRKSRC}
	${MV} ${WRKDIR}/bsd-games-2.17/sail/*.[ch] ${WRKSRC}/sail/
	${MV} ${WRKDIR}/bsd-games-2.17/sail/pathnames.h.in ${WRKSRC}/sail/pathnames.h

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
