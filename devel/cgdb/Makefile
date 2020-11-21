# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	cgdb
DISTVERSION=	0.7.1
CATEGORIES=	devel
MASTER_SITES=	http://cgdb.me/files/

MAINTAINER=	serio.jeffrey@gmail.com
COMMENT=	Curses-based interface to the GNU Debugger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo ncurses:base readline # fails with ncurses:port because readline is linked with ncurses:base

GNU_CONFIGURE=	yes

INFO=		cgdb

MAKE_JOBS_UNSAFE=	yes # because: make[4]: don't know how to make ./libtokenizer.a. Stop

# we need this for openpty(3) . It sucks,
# but since cgdb include a libutil itself,
# we have to specify the full path.
LDFLAGS+=	/usr/lib/libutil.so

post-patch:
	@${REINPLACE_CMD} -e 's|dev_ptmx=yes|dev_ptmx=no|' ${WRKSRC}/configure

.include <bsd.port.mk>
