# New ports collection makefile for:	Test::Fixture::DBI
# Date created:		26 Dec 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Fixture-DBI
PORTVERSION=	0.06
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to load fixture data into database

RUN_DEPENDS=	\
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-SQL-Abstract>0:${PORTSDIR}/databases/p5-SQL-Abstract \
	p5-SQL-Abstract-Plugin-InsertMulti>0:${PORTSDIR}/databases/p5-SQL-Abstract-Plugin-InsertMulti \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	make_database_yaml.pl.1 \
	make_fixture_yaml.pl.1
MAN3=	Test::Fixture::DBI.3 \
	Test::Fixture::DBI::Util.3 \
	Test::Fixture::DBI::Util::SQLite.3 \
	Test::Fixture::DBI::Util::mysql.3

.include <bsd.port.mk>
