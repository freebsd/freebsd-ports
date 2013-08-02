# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Parse-ErrorString-Perl
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse error messages from the Perl interpreter

BUILD_DEPENDS=	p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Class-XSAccessor>=0:${PORTSDIR}/devel/p5-Class-XSAccessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		check_perldiag.1
MAN3=		Parse::ErrorString::Perl.3 \
		Parse::ErrorString::Perl::ErrorItem.3 \
		Parse::ErrorString::Perl::StackItem.3

.include <bsd.port.mk>
