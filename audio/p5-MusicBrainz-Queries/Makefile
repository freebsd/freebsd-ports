# New ports collection makefile for:	p5-MusicBrainz-Queries
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	MusicBrainz-Queries
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	# none
PKGNAMEPREFIX=	p5-
DISTFILES=	# none

MAINTAINER=	knu@freebsd.org
COMMENT=	A Perl module that provides the musicbrainz query constants

EXTRACT_DEPENDS=	${NONEXISTENT}:${LIBMUSICBRAINZ_PORTDIR}:patch
LIB_DEPENDS=	musicbrainz.4:${LIBMUSICBRAINZ_PORTDIR}

LIBMUSICBRAINZ_PORTDIR=	${PORTSDIR}/audio/libmusicbrainz

PERL_CONFIGURE=	yes

MAN3=		MusicBrainz::Queries.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `cd ${LIBMUSICBRAINZ_PORTDIR}; ${MAKE} -V WRKSRC`/perl/Queries ${WRKSRC}

.include <bsd.port.post.mk>
