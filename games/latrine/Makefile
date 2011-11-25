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
CPPFLAGS+=	-I${LOCALBASE}/include -D_XOPEN_SOURCE_EXTENDED
LDFLAGS+=	-L${LOCALBASE}/lib
USE_CSTD=	gnu89
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_NCURSES=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1=		latrine.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,ncursesw/ncurses.h,ncurses.h,' \
		${WRKSRC}/charset.h ${WRKSRC}/screen.c

.include <bsd.port.post.mk>
