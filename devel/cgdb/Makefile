# New ports collection makefile for:	cgdb
# Date created:		2005-12-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cgdb
PORTVERSION=	0.6.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	A curses-based interface to the GNU Debugger

INFO=		cgdb
MAN1=		cgdb.1

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes

.include <bsd.port.pre.mk>

# at this time we can not use LIB_DEPENDS please read ports/99327
.if ${OSVERSION} < 700016
BUILD_DEPENDS+=	${LOCALBASE}/lib/libreadline.so.5:${PORTSDIR}/devel/readline
RUN_DEPENDS=	${BUILD_DEPENDS}
LDFLAGS+=	-rpath ${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-readline=${LOCALBASE}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
.endif

.include <bsd.port.post.mk>
