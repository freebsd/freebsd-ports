# $FreeBSD$

PORTNAME=	CHI-Driver-DBI
PORTVERSION=	1.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JSWARTZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	jeremybbaggs@gmail.com
COMMENT=	Use DBI for CHI unified cache interface storage

BUILD_DEPENDS=	p5-CHI>=0.241:${PORTSDIR}/devel/p5-CHI \
		p5-DBI>=1.26:${PORTSDIR}/databases/p5-DBI \
		p5-Moose>=0.66:${PORTSDIR}/devel/p5-Moose \
		p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
