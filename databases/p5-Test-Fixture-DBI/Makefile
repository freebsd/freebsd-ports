# $FreeBSD$

PORTNAME=	Test-Fixture-DBI
PORTVERSION=	0.07
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
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Sub-Uplevel>=0:${PORTSDIR}/devel/p5-Sub-Uplevel

USES=		perl5
USE_PERL5=	configure

MAN1=	make_database_yaml.pl.1 \
	make_fixture_yaml.pl.1
MAN3=	Test::Fixture::DBI.3 \
	Test::Fixture::DBI::Util.3 \
	Test::Fixture::DBI::Util::SQLite.3 \
	Test::Fixture::DBI::Util::mysql.3

.include <bsd.port.mk>
