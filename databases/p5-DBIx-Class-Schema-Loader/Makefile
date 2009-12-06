# New ports collection makefile for:	databases/p5-DBIx-Class-Schema-Loader
# Date created:				4 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Schema-Loader
PORTVERSION=	0.04006
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamic definition of a DBIx::Class::Schema

RUN_DEPENDS=	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Class-Accessor>=0.30:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-C3>=0.18:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Class-Data-Accessor>=0.03:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-DBIx-Class>=0.07006:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Data-Dump>=1.06:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Lingua-EN-Inflect-Number>=1.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		p5-UNIVERSAL-require>=0.11:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-DBD-SQLite>=1.12:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.56:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	5.8.0+

MAN3=	DBIx::Class::Schema::Loader.3 \
	DBIx::Class::Schema::Loader::Base.3 \
	DBIx::Class::Schema::Loader::DBI.3 \
	DBIx::Class::Schema::Loader::DBI::DB2.3 \
	DBIx::Class::Schema::Loader::DBI::Pg.3 \
	DBIx::Class::Schema::Loader::DBI::SQLite.3 \
	DBIx::Class::Schema::Loader::DBI::Writing.3 \
	DBIx::Class::Schema::Loader::DBI::mysql.3 \
	DBIx::Class::Schema::Loader::DBI::Oracle.3 \
	DBIx::Class::Schema::Loader::RelBuilder.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^\s*(test_requires|auto_install|recommends|configure_requires)/ or /^my/ .. /^}\s*$$/' ${WRKSRC}/Makefile.PL

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -print0 | ${XARGS} -0 ${RM}

OPTIONS=	SQLITE "SQLite Support" Off \
		MYSQL "MySQL Support" Off \
		PG "PostgreSQL Support" Off \
		ORACLE "Oracle Support (experimental)" Off

.include <bsd.port.pre.mk>

.if defined(WITH_SQLITE)
RUN_DEPENDS+=	p5-DBD-SQLite>=1.12:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1.56:${PORTSDIR}/databases/p5-DBI
.endif
.if defined(WITH_MYSQL)
RUN_DEPENDS+=	p5-DBD-mysql>=4.004:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>=1.56:${PORTSDIR}/databases/p5-DBI
.endif
.if defined(WITH_PG)
RUN_DEPENDS+=	p5-DBD-Pg>=1.49:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBI>=1.56:${PORTSDIR}/databases/p5-DBI
.endif
.if defined(WITH_ORACLE)
RUN_DEPENDS+=	p5-DBD-Oracle>=0.19:${PORTSDIR}/databases/p5-DBD-Oracle \
		p5-DBI>=1.56:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
