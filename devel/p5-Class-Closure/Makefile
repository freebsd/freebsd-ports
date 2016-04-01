# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-Closure
PORTVERSION=	0.302
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Encapsulated, declarative classes in Perl

BUILD_DEPENDS=	p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Devel-Caller>=0:devel/p5-Devel-Caller \
		p5-Sentinel>=0:devel/p5-Sentinel
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
