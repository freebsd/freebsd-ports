# $FreeBSD$

PORTNAME=	Test-Most
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for most commonly needed test functions and features

RUN_DEPENDS=	\
	p5-Exception-Class>=1.14:${PORTSDIR}/devel/p5-Exception-Class \
	p5-Test-Deep>=0.106:${PORTSDIR}/devel/p5-Test-Deep \
	p5-Test-Differences>=0.61:${PORTSDIR}/devel/p5-Test-Differences \
	p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Test-Warn>=0.23:${PORTSDIR}/devel/p5-Test-Warn
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
