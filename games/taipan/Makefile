# New ports collection makefile for:	taipan
# Date created:				2002-03-15
# Whom:					Dave Walton <dwalton@acm.org>
#
# $FreeBSD$
#

PORTNAME=	taipan
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.ilbbs.com/pub/linux/
MASTER_SITE_SUBDIR=	games/textrpg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Taipan was (and is) a classic role-playing game from the 1980s

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/taipan ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
