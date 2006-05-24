# New ports collection makefile for:	databases/p5-DBIx-Class-Schema-Loader
# Date created:				4 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Schema-Loader
PORTVERSION=	0.03000
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Dynamic definition of a DBIx::Class::Schema

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-DBI>=1.50:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=1.12:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-Simple>=0.32:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Data-Dump>=1.06:${PORTSDIR}/devel/p5-Data-Dump \
		p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Lingua-EN-Inflect-Number>=1.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced \
		p5-Class-Accessor>=0.22:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Accessor>=0.02:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-Class-C3>=0.11:${PORTSDIR}/devel/p5-Class-C3 \
		p5-DBIx-Class>=0.06000:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector

PERL_MODBUILD=	yes

MAN3=	DBIx::Class::Schema::Loader.3 \
	DBIx::Class::Schema::Loader::Base.3 \
	DBIx::Class::Schema::Loader::DBI.3 \
	DBIx::Class::Schema::Loader::DBI::DB2.3 \
	DBIx::Class::Schema::Loader::DBI::Pg.3 \
	DBIx::Class::Schema::Loader::DBI::SQLite.3 \
	DBIx::Class::Schema::Loader::DBI::Writing.3 \
	DBIx::Class::Schema::Loader::DBI::mysql.3 \
	DBIx::Class::Schema::Loader::RelBuilder.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
