# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Data-Currency
PORTVERSION=	0.06000
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Container class for currency conversion/formatting

BUILD_DEPENDS=	p5-Locale-Currency-Format>=0:${PORTSDIR}/finance/p5-Locale-Currency-Format \
		p5-Class-Accessor-Grouped>=0:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
		p5-Finance-Currency-Convert-WebserviceX>=0:${PORTSDIR}/finance/p5-Finance-Currency-Convert-WebserviceX \
		p5-Locale-Codes>=0:${PORTSDIR}/misc/p5-Locale-Codes \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector
RUN_DEPENDS=	p5-Locale-Currency-Format>=0:${PORTSDIR}/finance/p5-Locale-Currency-Format \
		p5-Class-Accessor-Grouped>=0:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
		p5-Finance-Currency-Convert-WebserviceX>=0:${PORTSDIR}/finance/p5-Finance-Currency-Convert-WebserviceX \
		p5-Locale-Codes>=0:${PORTSDIR}/misc/p5-Locale-Codes \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
