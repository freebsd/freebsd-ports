# $FreeBSD$

PORTNAME=	Scope-Container-DBI
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	DB connection manager with Scope::Container

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-DBI>=1.615:databases/p5-DBI \
		p5-Log-Minimal>=0:devel/p5-Log-Minimal \
		p5-Scope-Container>=0.04:devel/p5-Scope-Container \
		p5-Try-Tiny>=0.11:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-Test-SharedFork>=0:devel/p5-Test-SharedFork

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/Scope/Container/DBI.pm \
		${SITE_MAN3_REL}/Scope::Container::DBI.3.gz

.include <bsd.port.mk>
