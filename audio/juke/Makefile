# New ports collection makefile for:    juke
# Date created:         2 May 1999
# Whom:                 oyvindmo@initio.no
#
# $FreeBSD$
#

PORTNAME=		juke
PORTVERSION=		0.7
CATEGORIES=		audio
MASTER_SITES=		http://www.moll.no/oyvind/distfiles/\
			http://www.orakel.ntnu.no/~oyvindmo/distfiles/

MAINTAINER=		oyvind@moll.no
COMMENT=	A simple curses/ncurses based juke box program

GNU_CONFIGURE=		yes

MAN1=			juke.1

.if defined(WITH_VI_BINDINGS)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-vi
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/juke.conf ${PREFIX}/etc/juke.conf.sample
	@${SED} 's,PREFIX,${PREFIX},' ${PKGMESSAGE}

.include <bsd.port.mk>
