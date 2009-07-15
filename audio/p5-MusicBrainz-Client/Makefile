# New ports collection makefile for:	p5-MusicBrainz-Client
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	MusicBrainz-Client
PORTVERSION=	0.11
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl module that provides access to the musicbrainz client API

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MusicBrainz/Queries.pm:${PORTSDIR}/audio/p5-MusicBrainz-Queries
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MusicBrainz::Client.3 \
		MusicBrainz::Client::Simple.3 \
		MusicBrainz::Client::Simple::Album.3 \
		MusicBrainz::Client::Simple::Artist.3 \
		MusicBrainz::Client::Simple::Track.3

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
