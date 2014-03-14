# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Admin-DSNManager
PORTVERSION=	2.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manage a file of DSNs, for both testing and production

LICENSE=	ART20

BUILD_DEPENDS=	p5-Config-Tiny>=2.12:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-File-Slurp>=9999.13:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Moo>=1.004002:${PORTSDIR}/devel/p5-Moo
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Version>=1.002.003:${PORTSDIR}/devel/p5-Test-Version \
		p5-Try-Tiny>=0.06:${PORTSDIR}/lang/p5-Try-Tiny

USE_PERL5=	configure
USES=		perl5 tar:tgz

.include <bsd.port.mk>
