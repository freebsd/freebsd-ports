# Created by: Mark Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdgames
PORTVERSION=	3.8.1
PORTEPOCH=	1
CATEGORIES=	games
# Fetched from http://gitweb.dragonflybsd.org/dragonfly.git/tree/v${PORTVERSION}:/games
# Content is stable, but file timestamps differ. Bad gitweb, no cookie!
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Traditional BSD games taken from DragonFly BSD

CONFLICTS=	hangman-*

USES=		tar:xz
#WRKSRC=		${WRKDIR}/dragonfly
MAKE_ENV+=	NO_WERROR=1

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
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's|/var/games/|${PREFIX}&|g'

pre-install:
.for d in atc larn quiz.db
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/$d
.endfor
.for d in atc battlestar hackdir/save larn phantasia
	@${MKDIR} ${STAGEDIR}${PREFIX}/var/games/$d
.endfor

post-install:
	@${TOUCH} ${STAGEDIR}${PREFIX}/var/games/atc_score
	@${FIND} ${STAGEDIR}${PREFIX}/var/games -type f -exec ${MV} {} {}.sample \;

.include <bsd.port.mk>
