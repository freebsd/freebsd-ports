# New ports collection makefile for:	databases/p5-DBIx-Class-Schema-Loader
# Date created:				4 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Schema-Loader
PORTVERSION=	0.02007
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Dynamic definition of a DBIx::Class::Schema

BUILD_DEPENDS=	p5-DBIx-Class>=0.05006:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced \
		p5-Class-Accessor>=0.22:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Accessor>=0.02:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-Class-C3>=0.09:${PORTSDIR}/devel/p5-Class-C3 \
		p5-DBI>=1.40:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=1.11:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Test-Simple>=0.32:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	DBIx::Class::Schema::Loader.3 \
	DBIx::Class::Schema::Loader::DB2.3 \
	DBIx::Class::Schema::Loader::Generic.3 \
	DBIx::Class::Schema::Loader::Pg.3 \
	DBIx::Class::Schema::Loader::SQLite.3 \
	DBIx::Class::Schema::Loader::Writing.3 \
	DBIx::Class::Schema::Loader::mysql.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
