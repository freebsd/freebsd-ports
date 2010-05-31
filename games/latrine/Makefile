# New ports collection makefile for:	latrine
# Date created:		Sun Feb 18 01:13:42 CET 2007
# Whom:			Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	latrine
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://people.debian.org/~godisch/latrine/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Curses-based LAnguage TRaINEr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"CFLAGS=-I${LOCALBASE}/include -I${WRKDIR} -D_XOPEN_SOURCE_EXTENDED" LDFLAGS=-L${LOCALBASE}/lib
USE_GMAKE=	yes
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1=		latrine.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
	${MKDIR} ${WRKDIR}/ncursesw
	${LN} -s ${LOCALBASE}/include/ncurses/ncurses.h ${WRKDIR}/ncursesw/ncurses.h
.else
	@${REINPLACE_CMD} -e 's,ncursesw/ncurses.h,ncurses.h,' \
		${WRKSRC}/charset.h ${WRKSRC}/screen.c
.endif

.include <bsd.port.post.mk>
