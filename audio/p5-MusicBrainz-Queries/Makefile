# New ports collection makefile for:	p5-MusicBrainz-Queries
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	MusicBrainz-Queries
PORTVERSION=	0.11
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl module that provides the musicbrainz query constants

BUILD_DEPENDS=	${LOCALBASE}/include/musicbrainz/queries.h:${PORTSDIR}/audio/libmusicbrainz

PERL_CONFIGURE=	yes

MAN3=		MusicBrainz::Queries.3

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
