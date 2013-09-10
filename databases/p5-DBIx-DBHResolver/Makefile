# $FreeBSD$

PORTNAME=	DBIx-DBHResolver
PORTVERSION=	0.17
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to resolve DB connection with many database servers

RUN_DEPENDS=	\
	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-Config-Any>0:${PORTSDIR}/devel/p5-Config-Any \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-Data-Util>0:${PORTSDIR}/devel/p5-Data-Util \
	p5-Hash-Merge-Simple>0:${PORTSDIR}/devel/p5-Hash-Merge-Simple \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Sub-Uplevel>=0:${PORTSDIR}/devel/p5-Sub-Uplevel
# TODO: fix test.

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::DBHResolver.3 \
	DBIx::DBHResolver::Strategy.3 \
	DBIx::DBHResolver::Strategy::Key.3 \
	DBIx::DBHResolver::Strategy::List.3 \
	DBIx::DBHResolver::Strategy::Range.3 \
	DBIx::DBHResolver::Strategy::Remainder.3 \
	DBIx::DBHResolver::Strategy::RoundRobin.3

.include <bsd.port.mk>
