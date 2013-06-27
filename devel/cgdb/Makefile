# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	cgdb
PORTVERSION=	0.6.7
CATEGORIES=	devel
MASTER_SITES=	http://cgdb.me/files/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A curses-based interface to the GNU Debugger

INFO=		cgdb
MAN1=		cgdb.1

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

# we need this for openpty(3) . It sucks,
# but since cgdb include a libutil itself,
# we have to specify the full path.
LDFLAGS+=	/usr/lib/libutil.so

.include <bsd.port.pre.mk>

# at this time we can not use LIB_DEPENDS, please read ports/99327
.if ${OSVERSION} < 700016
BUILD_DEPENDS+=	${LOCALBASE}/lib/libreadline.so.6:${PORTSDIR}/devel/readline
RUN_DEPENDS:=	${BUILD_DEPENDS}
LDFLAGS+=	-rpath ${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-readline=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|dev_ptmx=yes|dev_ptmx=no|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
