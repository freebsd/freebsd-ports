# New ports collection makefile for:	frotz
# Date created:				16 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	frotz
PORTVERSION=	2.40
CATEGORIES=	games
MASTER_SITES=	http://www.cs.csubak.edu/~dgriffi/frotz/files/ \
		ftp://ftp.gmd.de/if-archive/infocom/interpreters/frotz/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	# empty

MAN6=		frotz.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/frotz.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/frotz
.for file in AUTHORS BUGS ChangeLog HOW_TO_PLAY INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/frotz
.endfor
.endif

.include <bsd.port.mk>
