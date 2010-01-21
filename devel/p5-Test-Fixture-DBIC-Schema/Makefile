# New ports collection makefile for:	devel/p5-Test-Fixture-DBIC-Schema
# Date created:				23 Oct 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Fixture-DBIC-Schema
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Module providing a DBIx::Class::Schema fixture data loader

RUN_DEPENDS=	p5-DBIx-Class>=0.07005:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Kwalify>=1.19:${PORTSDIR}/textproc/p5-Kwalify \
		p5-Params-Validate>=0.15:${PORTSDIR}/devel/p5-Params-Validate \
		p5-YAML-Syck>=0.95:${PORTSDIR}/textproc/p5-YAML-Syck

PERL_CONFIGURE=	yes

MAN3=		Test::Fixture::DBIC::Schema.3

.include <bsd.port.mk>
