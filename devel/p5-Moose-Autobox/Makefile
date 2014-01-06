# Created by: Bill Brinzer <bill.brinzer@gmail.com>
# $FreeBSD$

PORTNAME=	Moose-Autobox
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Autoboxed wrappers for Native Perl datatypes

BUILD_DEPENDS=	p5-autobox>=2.23:${PORTSDIR}/devel/p5-autobox \
		p5-Moose>=0.42:${PORTSDIR}/devel/p5-Moose \
		p5-Perl6-Junction>=1.40000:${PORTSDIR}/devel/p5-Perl6-Junction
RUN_DEPENDS=	p5-autobox>=2.23:${PORTSDIR}/devel/p5-autobox \
		p5-Moose>=0.42:${PORTSDIR}/devel/p5-Moose \
		p5-Perl6-Junction>=1.40000:${PORTSDIR}/devel/p5-Perl6-Junction
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
