# $FreeBSD$

PORTNAME=	Throwable
PORTVERSION=	0.200008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use class for error objects

RUN_DEPENDS=	p5-Class-Load>=0.20:${PORTSDIR}/devel/p5-Class-Load \
		p5-Devel-StackTrace>=1.21:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Moo>=1.000001:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		StackTrace::Auto.3 Throwable.3 Throwable::Error.3

.include <bsd.port.mk>
