# $FreeBSD$

PORTNAME=	DBIx-Connector
PORTVERSION=	0.56
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, safe DBI connection management

RUN_DEPENDS=	p5-DBI>=1.605:databases/p5-DBI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-MockModule>=0:devel/p5-Test-MockModule

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
