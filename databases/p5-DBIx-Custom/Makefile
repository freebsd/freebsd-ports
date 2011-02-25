# New ports collection makefile for:	DBIx-Custom
# Date created:		27 December 2009
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Custom
PORTVERSION=	0.1651
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/K/KI/KIMOTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Customizable DBI

BUILD_DEPENDS=	p5-DBD-SQLite>=1.25:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.60.5:${PORTSDIR}/databases/p5-DBI \
		p5-Object-Simple>=3.0616:${PORTSDIR}/devel/p5-Object-Simple \
		p5-Time-Piece>=1.15:${PORTSDIR}/devel/p5-Time-Piece
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES
MAN3=	DBIx::Custom.3 \
	DBIx::Custom::Guide.3 \
	DBIx::Custom::Guide::Ja.3 \
	DBIx::Custom::Model.3 \
	DBIx::Custom::MySQL.3 \
	DBIx::Custom::Query.3 \
	DBIx::Custom::QueryBuilder.3 \
	DBIx::Custom::Result.3 \
	DBIx::Custom::SQLite.3 \
	DBIx::Custom::Tag.3 \
	DBIx::Custom::Where.3

.include <bsd.port.mk>
