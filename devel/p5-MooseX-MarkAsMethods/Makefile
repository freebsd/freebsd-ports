# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-MarkAsMethods
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mark overload code symbols as methods

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0:devel/p5-B-Hooks-EndOfScope \
		p5-Moose>=0.94:devel/p5-Moose \
		p5-namespace-autoclean>=0.12:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
