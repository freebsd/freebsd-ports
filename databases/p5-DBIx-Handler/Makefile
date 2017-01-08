# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	DBIx-Handler
PORTVERSION=	0.14
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Fork-safe and easy transaction handling DBI handler

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-DBI>=1.605:databases/p5-DBI \
		p5-DBIx-TransactionManager>=1.09:databases/p5-DBIx-TransactionManager
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-SharedFork>=0.16:devel/p5-Test-SharedFork

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
