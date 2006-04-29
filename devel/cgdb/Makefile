# New ports collection makefile for:	cgdb
# Date created:		2005-12-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cgdb
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gslin@gslin.org
COMMENT=	A curses-based interface to the GNU Debugger

INFO=		cgdb
MAN1=		cgdb.1
PLIST_FILES=	bin/cgdb

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700016
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

post-patch:
	${REINPLACE_CMD} -e 's,libutil\.h,,g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
