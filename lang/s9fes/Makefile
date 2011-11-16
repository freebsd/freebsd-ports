# New ports collection makefile for:	s9fes
# Date created:				23 February 2009
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	s9fes
PORTVERSION=	20101004
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.t3x.org/misc/

MAINTAINER=	nmh@t3x.org
COMMENT=	A portable Scheme interpreter with a Unix interface

MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}" PREFIX=${PREFIX} LIBDIR=${DATADIR}
WRKSRC=		${WRKDIR}/s9

MAN1=		s9.1
MANCOMPRESSED=	yes

post-patch:
# Fix parallel (-jX) build: add missing target prerequisite
	@${REINPLACE_CMD} -e '/^arse-core.image/s,:,: s9,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
