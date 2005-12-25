# New ports collection makefile for:	cgdb
# Date created:		2005-12-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cgdb
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	A curses-based interface to the GNU Debugger

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/cgdb

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
# This port requires readline 4.2 or newer, which is only available
# in the base system in FreeBSD 5.x or later.
BUILD_DEPENDS+=		${LOCALBASE}/lib/libreadline.so.5:${PORTSDIR}/devel/readline
RUN_DEPENDS+=		${LOCALBASE}/lib/libreadline.so.5:${PORTSDIR}/devel/readline
CONFIGURE_ARGS+=	--with-readline=${LOCALBASE}
.endif

post-patch:
	${REINPLACE_CMD} -e 's,libutil\.h,,g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
