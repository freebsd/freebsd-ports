# New ports collection makefile for:	hunt
# Date created:				2001-02-20
# Whom:					bdluevel@heitec.net
#
# $FreeBSD$
#
# the files are not packed at the master site,
# so they must be retrieved one by one

PORTNAME=	hunt
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.pvv.ntnu.no/.disk4a/4.4BSD-Lite2/untarred/usr/src/contrib/hunt/
DISTFILES=	Makefile README answer.c bsd.h connect.c ctl.c ctl_transact.c \
		draw.c driver.c execute.c expl.c extern.c faketalk.c get_names.c \
		hunt.6 hunt.c hunt.h huntd.6 makemaze.c otto.c pathname.c playit.c \
		shots.c talk_ctl.h terminal.c

MAINTAINER=    bdluevel@heitec.net

DIST_SUBDIR=	${PORTNAME}

MAN6=			hunt.6 huntd.6

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -p ${DISTDIR}/${DIST_SUBDIR}/* ${WRKSRC}

.include <bsd.port.mk>
