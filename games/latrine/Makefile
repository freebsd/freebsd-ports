# New ports collection makefile for:	latrine
# Date created:		Sun Feb 18 01:13:42 CET 2007
# Whom:			Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	latrine
PORTVERSION=	0.9.0
CATEGORIES=	games
MASTER_SITES=	http://www.godisch.de/debian/latrine/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Curses-based LAnguage TRaINEr

LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"CFLAGS=-I${LOCALBASE}/include -I${WRKDIR} -D_XOPEN_SOURCE_EXTENDED" LDFLAGS=-L${LOCALBASE}/lib --mandir=${PREFIX}/man
USE_GMAKE=	yes
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1=		latrine.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		needs libcursesw which doesnt work on this OSVERSION
.endif

post-extract:
	${MKDIR} ${WRKDIR}/ncursesw
	${LN} -s ${LOCALBASE}/include/ncurses/ncurses.h ${WRKDIR}/ncursesw/ncurses.h

.include <bsd.port.post.mk>
