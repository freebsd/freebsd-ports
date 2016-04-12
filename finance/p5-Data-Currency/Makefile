# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Data-Currency
PORTVERSION=	0.06000
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Container class for currency conversion/formatting

BUILD_DEPENDS=	p5-Class-Accessor-Grouped>=0:devel/p5-Class-Accessor-Grouped \
		p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-Finance-Currency-Convert-WebserviceX>=0:finance/p5-Finance-Currency-Convert-WebserviceX \
		p5-Locale-Codes>=0:misc/p5-Locale-Codes \
		p5-Locale-Currency-Format>=0:finance/p5-Locale-Currency-Format
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
