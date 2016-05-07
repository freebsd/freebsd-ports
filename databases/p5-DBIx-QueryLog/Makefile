# $FreeBSD$

PORTNAME=	DBIx-QueryLog
PORTVERSION=	0.41
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for logging queries for DBI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-DBI>0:databases/p5-DBI \
	p5-Text-ASCIITable>0:textproc/p5-Text-ASCIITable
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>0:databases/p5-DBD-SQLite \
	p5-Class-Method-Modifiers>0:devel/p5-Class-Method-Modifiers \
	p5-Test-Requires>0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
