# $FreeBSD$

PORTNAME=	DBIx-Class-Storage-TxnEndHook
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Transaction hook provider for DBIx::Class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build>=0.38:devel/p5-Module-Build
RUN_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	modbuild

.include <bsd.port.mk>
