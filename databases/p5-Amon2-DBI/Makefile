# $FreeBSD$

PORTNAME=	Amon2-DBI
PORTVERSION=	0.32
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of simple DBI wrapper

RUN_DEPENDS=	\
	p5-Carp-Clan>0:${PORTSDIR}/devel/p5-Carp-Clan \
	p5-DBI>=1.616:${PORTSDIR}/databases/p5-DBI \
	p5-DBIx-TransactionManager>=1.09:${PORTSDIR}/databases/p5-DBIx-TransactionManager \
	p5-SQL-Interp>=1.10:${PORTSDIR}/databases/p5-SQL-Interp
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-Amon2>0:${PORTSDIR}/www/p5-Amon2 \
	p5-Test-Memory-Cycle>0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

PERL_CONFIGURE=	yes

MAN3=	Amon2::DBI.3

.include <bsd.port.mk>
