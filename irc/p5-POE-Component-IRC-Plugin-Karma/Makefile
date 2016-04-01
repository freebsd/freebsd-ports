# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-Karma
PORTVERSION=	0.003
PORTREVISION=	1
CATEGORIES=	irc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:APOCAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PoCo-IRC plugin that keeps track of karma

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-POE-Component-IRC>=6.22:irc/p5-POE-Component-IRC \
		p5-Moose>=0:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
