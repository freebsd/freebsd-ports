# Created by: gahr
# $FreeBSD$

PORTNAME=	etcd
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~gahr/distfiles/ \
		http://www.gahr.ch/etcd/
MASTER_SITE_SUBDIR=	gahr

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enhanced Tiny CD, a simple ncurses-based CD player

USE_SDL=	sdl

MAKE_ARGS=	INCDIR=${LOCALBASE}/include LIBDIR=${LOCALBASE}/lib \
		SDL_LIBS="-lSDL -pthread" NCURSES_LIBS="-lncursesw"

PLIST_FILES=	bin/etcd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/etcd ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
