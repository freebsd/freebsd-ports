# New ports collection Makefile for:	etcd
# Date created:				2 October 2009
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	etcd
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~gahr/distfiles/ \
		http://www.gahr.ch/etcd/
MASTER_SITE_SUBDIR=	gahr

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enhanced Tiny CD, a simple ncurses-based CD player

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

USE_SDL=	sdl
MANCOMPRESSED=	no

MAKE_ARGS=	INCDIR=${LOCALBASE}/include LIBDIR=${LOCALBASE}/lib \
		SDL_LIBS=-lSDL MB_LIBS=-lmusicbrainz \
		NCURSES_LIBS="-lncursesw ${PTHREAD_LIBS}"

PLIST_FILES=	bin/etcd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/etcd ${PREFIX}/bin/

.include <bsd.port.mk>
