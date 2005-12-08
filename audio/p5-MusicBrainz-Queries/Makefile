# New ports collection makefile for:	p5-MusicBrainz-Queries
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	MusicBrainz-Queries
PORTVERSION=	0.09
PORTREVISION=	0
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SV/SVANZOEST
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl module that provides the musicbrainz query constants

BUILD_DEPENDS=	${LOCALBASE}/include/musicbrainz/queries.h:${PORTSDIR}/audio/libmusicbrainz

PERL_CONFIGURE=	yes

MAN3=		MusicBrainz::Queries.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
