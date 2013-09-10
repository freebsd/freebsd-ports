# $FreeBSD$

PORTNAME=	Class-DBI-Plugin-Iterator
PORTVERSION=	0.13
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	New iterator for p5-Class-DBI

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI
TEST_DEPENDS=	p5-DBD-SQLite>=1.27:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Class-DBI-Pager>=0:${PORTSDIR}/databases/p5-Class-DBI-Pager

USES=		perl5
USE_PERL5=	configure
MAN3=		Class::DBI::Plugin::Iterator.3 \
		Class::DBI::Plugin::Iterator::Nihongo.3

.include <bsd.port.mk>
