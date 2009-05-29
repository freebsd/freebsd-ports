# New ports collection makefile for:	amy
# Date created:				30 Jan 2003
# Whom:					Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=	amy
PORTVERSION=	0.8.7
CATEGORIES=	games
MASTER_SITES=	http://tgreiner.net/
DISTFILES=	amy-${PORTVERSION}.tar.gz ClassicGames.pgn.bz2
EXTRACT_ONLY=	amy-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A chess program for playing and analyzing games

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2:install

DEPRECATED=		mastersite disappeared, does not build on recent version
EXPIRATION_DATE=	2009-07-28

NOT_FOR_ARCHS=	sparc64 alpha

MAN6=		Amy.6

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.if ${ARCH} == "amd64"
BROKEN=		Segfault during build on amd64
.endif

post-extract:
	${BZCAT} ${DISTDIR}/ClassicGames.pgn.bz2 > \
		${WRKSRC}/PGN/ClassicGames.pgn

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
