# New ports collection makefile for:	p5-WWW-Mechanize
# Date created:				2005-02-13
# Whom:	      				aturetta@commit.it
#
# $FreeBSD$
#

PORTNAME=	Test-WWW-Mechanize
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Testing-specific WWW::Mechanize subclass

RUN_DEPENDS=	p5-Carp-Assert-More>=0:${PORTSDIR}/devel/p5-Carp-Assert-More \
		p5-HTTP-Server-Simple>=0.35:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Test-LongString>=0.07:${PORTSDIR}/devel/p5-Test-LongString \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.24:${PORTSDIR}/www/p5-WWW-Mechanize
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::WWW::Mechanize.3

.include <bsd.port.mk>
