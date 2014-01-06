# $FreeBSD$

PORTNAME=	Data-Record
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Data::Record - "split" on steroids

RUN_DEPENDS=	p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Hash-Util-FieldHash-Compat>0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat
BUILD_DEPENDS=	p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Hash-Util-FieldHash-Compat>0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat \
		p5-ExtUtils-CBuilder>0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Scope-Guard>=0.20:${PORTSDIR}/devel/p5-Scope-Guard

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
