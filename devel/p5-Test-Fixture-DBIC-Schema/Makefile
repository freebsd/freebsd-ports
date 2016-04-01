# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Fixture-DBIC-Schema
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module providing a DBIx::Class::Schema fixture data loader

BUILD_DEPENDS=	p5-DBIx-Class>=0.07005:databases/p5-DBIx-Class \
		p5-Kwalify>=1.19:textproc/p5-Kwalify \
		p5-Params-Validate>=0.15:devel/p5-Params-Validate \
		p5-YAML-Syck>=0.95:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
