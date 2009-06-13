# New ports collection makefile for:	p5-MusicBrainz-TRM
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	MusicBrainz-TRM
PORTVERSION=	0.02
PORTREVISION=	0
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl module that provides access to the musicbrainz client TRM API

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

PERL_CONFIGURE=	yes

MAN3=		MusicBrainz::TRM.3

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
