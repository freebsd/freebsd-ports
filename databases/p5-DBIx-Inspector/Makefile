# $FreeBSD$

PORTNAME=	DBIx-Inspector
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to get information from $dbh

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite \
	p5-DBI>0:databases/p5-DBI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>0:databases/p5-DBD-SQLite \
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Test-Simple>=0.94:devel/p5-Test-Simple

USES=	perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
