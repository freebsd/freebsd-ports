# New ports collection makefile for:    wolfpack
# Date created:                         26 October 1999
# Whom:                                 Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	wolfpack
PORTVERSION=	4.2.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.empire.cx/pub/empire/server/oldversions/
DISTNAME=	empire${PORTVERSION}

MAINTAINER=	darius@dons.net.au

.if !defined(BATCH)
IS_INTERACTIVE=	yes     # configure script asks questions
.endif
WRKSRC=		${WRKDIR}/emp4
ALL_TARGET=	freebsd

MAN1=		fairland.1 files.1 land.1 ore.1 pconfig.1 perfect.1
MAN6=		emp_client.6 emp_server.6

MAKE_ARGS=	PREFIX=${PREFIX}

post-install:
	${CHMOD} 750 ${PREFIX}/wolfpack/data
	${CHMOD} 755 ${PREFIX}/wolfpack/info.nr
	@${CAT} ${FILESDIR}/post-install-info

.include <bsd.port.mk>
