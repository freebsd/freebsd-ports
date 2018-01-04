# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	cgdb
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	http://cgdb.me/files/

MAINTAINER=	serio.jeffrey@gmail.com
COMMENT=	Curses-based interface to the GNU Debugger

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeinfo readline
INFO=		cgdb

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

# we need this for openpty(3) . It sucks,
# but since cgdb include a libutil itself,
# we have to specify the full path.
LDFLAGS+=	/usr/lib/libutil.so

post-patch:
	@${REINPLACE_CMD} -e 's|dev_ptmx=yes|dev_ptmx=no|' ${WRKSRC}/configure

.include <bsd.port.mk>
