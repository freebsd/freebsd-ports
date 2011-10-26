# New ports collection makefile for:	DBIx-Custom
# Date created:		27 December 2009
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Custom
PORTVERSION=	0.1739
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Customizable DBI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=1.25:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.60.5:${PORTSDIR}/databases/p5-DBI \
		p5-Object-Simple>=3.0621:${PORTSDIR}/devel/p5-Object-Simple
RUN_DEPENDS=	p5-DBD-SQLite>=1.25:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.60.5:${PORTSDIR}/databases/p5-DBI \
		p5-Object-Simple>=3.0621:${PORTSDIR}/devel/p5-Object-Simple

PERL_CONFIGURE=	yes

MAN3=		DBIx::Custom.3 \
		DBIx::Custom::Guide.3 \
		DBIx::Custom::Guide::Ja.3 \
		DBIx::Custom::Mapper.3 \
		DBIx::Custom::Model.3 \
		DBIx::Custom::NotExists.3 \
		DBIx::Custom::Order.3 \
		DBIx::Custom::Query.3 \
		DBIx::Custom::QueryBuilder.3 \
		DBIx::Custom::Result.3 \
		DBIx::Custom::Tag.3 \
		DBIx::Custom::Util.3 \
		DBIx::Custom::Where.3

.include <bsd.port.mk>
