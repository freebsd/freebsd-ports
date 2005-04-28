# New ports collection makefile for:	miscom
# Date created:				6 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		miscom
PORTVERSION=		1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade
DISTNAME=		${PORTNAME}

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Atari "Missile Command" clone

ALL_TARGET=
WRKSRC=			${WRKDIR}/miscom
MAN6=			miscom.6

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-DSOUNDSDIR='\"$(DATADIR)\"' -DSOUND_SUPPORT -DMORE_SOUNDBUF
.endif

MAKE_ARGS=	CC="${CC}" DATADIR="${DATADIR}" \
		CFLAGS="${CFLAGS}"

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/miscom ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/${MAN6} ${PREFIX}/man/man6
	@ ${MKDIR} ${PREFIX}/share/miscom
	@ ${INSTALL_DATA} ${WRKSRC}/sounds/* ${PREFIX}/share/miscom

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/miscom
.for file in COPYING ChangeLog README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/miscom
.endfor
.endif

.include <bsd.port.post.mk>
